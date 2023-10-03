//TODO: Estruturas e metodos que eu preciso implementar na mao:
/*
Pilha
    -push (adicionar elemento)
    -top (ver elemento do topo)
    -pop (remover elemento do topo)
    -empty (verificar se a pilha esta vazia)
    -construtor (inicializar a pilha vazia)
*/
//TODO: Outras coisas que eu preciso fazer:
/*
    -Tratamento de erro (principalmente se tiver caracteres inesperados na string de equacao)
    -Fazer o menu de opcoes 
    -Separar os arquivos, criar os cabeçalhos e montar o makefile
*/

#include <iostream>
#include <stack>

using namespace std;

const char characterToCompareNot = '~';
const char characterToCompareAnd = '&';
const char characterToCompareOr = '|';



//-------Converter expressão de infixa para posfixa no jeito da funcão de baixo calcular--------
string infixToPostfix(string logicExpression){
    string convertedExpression;
    stack<char> signals;

    for (int i =0 ; i<= logicExpression.size(); i++){
        char expressionMember = logicExpression[i];
        if (isalpha(expressionMember)){
            convertedExpression += expressionMember;
            }
        else if (expressionMember=='('){
            signals.push(expressionMember);
        }
        else if (expressionMember==')'){
            char actualSignalToRemove;
            do {
                actualSignalToRemove = signals.top();
                convertedExpression += actualSignalToRemove;
                signals.pop();
            } while (actualSignalToRemove != '(');
            //tirar o ultimo caractere da string convertida
            convertedExpression.pop_back();
        }
        else if (expressionMember=='~'){
            signals.push(expressionMember);
        }
        else if (expressionMember == '&'){
            char signalOnTop;
            do{
                if (signals.empty())
                    break;
                signalOnTop = signals.top();
                if (signalOnTop == '~'){
                    convertedExpression =+ signalOnTop;
                    signals.pop();
                }
                else{
                    break;
                }
            }while(1>0);
            signals.push(expressionMember);
        }
        else if (expressionMember == '|'){
            char signalOnTop;
            do{
                if (signals.empty())
                    break;
                signalOnTop = signals.top();
                if (signalOnTop == '~' || signalOnTop == '&'){
                    convertedExpression = convertedExpression + signalOnTop;
                    signals.pop();
                }
                else{
                    break;
                }
            }while(1>0);
            signals.push(expressionMember);
        }

    }
    while (!(signals.empty())){
        char signalToAdd = signals.top();
        convertedExpression = convertedExpression + signalToAdd;
        signals.pop();
    }
    return convertedExpression;

}
    
bool convertedLogicExpressionSolver (string logicExpressionWithInputs){
        //--------Resolver a expressão posfixa---------
        //Inicializar a pilha vazia
        std::stack<int> expressionValues;
        for (int i =0 ; i<= logicExpressionWithInputs.size(); i++){
            if (isdigit(logicExpressionWithInputs[i])){
                expressionValues.push(int(logicExpressionWithInputs[i]-'0'));
            }
            //fazer com swich case dps pra ficar + elegant
            else if (logicExpressionWithInputs[i] == characterToCompareAnd){
                int firstNum = expressionValues.top();
                expressionValues.pop();
                int secondNum = expressionValues.top();
                expressionValues.pop();

                int result = firstNum * secondNum;
                expressionValues.push(result);
            }
            else if (logicExpressionWithInputs[i] == characterToCompareOr){
                int firstNum = expressionValues.top();
                expressionValues.pop();
                int secondNum = expressionValues.top();
                expressionValues.pop();

                int result = firstNum + secondNum;
                expressionValues.push(result);

            }
            else if (logicExpressionWithInputs[i] == characterToCompareNot){
                int num = expressionValues.top();
                int result;
                expressionValues.pop();

                if (num == 0){
                    result = 1;
                }
                else if (num == 1){
                    result = 0;
                }
                expressionValues.push(result);
            }
        }
        return bool(expressionValues.top());
} 

string inputInsertionInExpression (string logicExpression, string inputValues){
    string convertedExpressionWithInputs;
    for (int i =0 ; i<= logicExpression.size(); i++){
        if (isalpha(logicExpression[i])){
            char letter = logicExpression[i];
            int num = letter - 'a' + 0;
            convertedExpressionWithInputs = convertedExpressionWithInputs + inputValues[num];
            
        }
        else {
            convertedExpressionWithInputs = convertedExpressionWithInputs + logicExpression[i];
        }
    }
    return convertedExpressionWithInputs;
}

int main() {
    std::string logicExpression;
    std::string inputValues;
    std::string convertedExpressionWithInputs;

    int option;
    std::cout<<("\n-----SELECIONE A FUNCAO A SER EXECUTADA-----\n");
    std::cout<<("1 - RESOLUCAO DE EXPRESSOES LOGICAS\n");
    std::cout<<("2 - RESOLUCAO DE SATISFABILIDADE\n");
    std::cin>>option;
    std::cout<<("\nVOCE ESCOLHEU A OPCAO:");cout<<option;cout<<("\n");

    //------RESOLUÇÃO DE EXPRESSOES LOGICAS (PARTE 1 TP)-------
    if (option==1){
        
        while (0<1){
            std::cout<<("\nINSIRA A EXPRESSAO LOGICA:\n");
            std::cin >> logicExpression;

            std::cout<<("\nINSIRA OS VALORES DE ENTRADA:\n");
            std::cin >> inputValues;

            //-------Converter expressão de infixa para posfixa--------
            logicExpression = infixToPostfix(logicExpression);

            //-------Substituir valores de entrada na expressão--------
            convertedExpressionWithInputs = inputInsertionInExpression(logicExpression, inputValues);
            bool expResult = convertedLogicExpressionSolver(convertedExpressionWithInputs);
            //resultado da funcao separada
            std::cout<<("\n-----resultado da expressao-----\n");
            std::cout<<(expResult);
            std::cout<<("\n----------------------------------------------------\n");

        }
    }

    //-------RESOLUÇÃO DE SATISFABILIDADE (PARTE 2 TP)--------
    else if (option==2){
        while (0<1){
            printf("\nNOT IMPLEMENTED\n");
        }
    }

}