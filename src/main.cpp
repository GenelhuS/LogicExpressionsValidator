#include <iostream>
#include <stack>

using namespace std;

const char characterToCompareNot = '~';
const char characterToCompareAnd = '&';
const char characterToCompareOr = '|';
//TODO: tirar esse div daqui
const char characterToCompareDiv = '/';



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
            //TODO: tirar o ultimo caractere da string convertida
            //convertedExpression = convertedExpression[:-1]
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
    


int main() {
    std::string logicExpression;
    std::string inputValues;

    while (0<1){
        std::cout<<("\nINSIRA A EXPRESSAO LOGICA:\n");
        std::cin >> logicExpression;

        std::cout<<("\nINSIRA OS VALORES DE ENTRADA:\n");
        std::cin >> inputValues;

        //-------Converter expressão de infixa para posfixa--------
        logicExpression = infixToPostfix(logicExpression);

        //--------Resolver a expressão posfixa---------
        //Inicializar a pilha vazia
        std::stack<int> expressionValues;
        for (int i =0 ; i<= logicExpression.size(); i++){
            if (isdigit(logicExpression[i])){
                expressionValues.push(int(logicExpression[i]-'0'));
            }
            //fazer com swich case dps pra ficar + elegant
            else if (logicExpression[i] == characterToCompareAnd){
                int firstNum = expressionValues.top();
                expressionValues.pop();
                int secondNum = expressionValues.top();
                expressionValues.pop();

                int result = firstNum * secondNum;
                expressionValues.push(result);
            }
            else if (logicExpression[i] == characterToCompareDiv){
                int firstNum = expressionValues.top();
                expressionValues.pop();
                int secondNum = expressionValues.top();
                expressionValues.pop();

                int result = firstNum / secondNum;
                expressionValues.push(result);
            }
            else if (logicExpression[i] == characterToCompareOr){
                int firstNum = expressionValues.top();
                expressionValues.pop();
                int secondNum = expressionValues.top();
                expressionValues.pop();

                int result = firstNum + secondNum;
                expressionValues.push(result);

            }
            else if (logicExpression[i] == characterToCompareNot){
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
        std::cout<<("\n-----VALOR DA EXPRESSAO-----\n");
        std::cout<<(expressionValues.top());
        std::cout<<("\n-----------------------------\n");
    }
}