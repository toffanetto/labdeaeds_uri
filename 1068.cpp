/*  @toffanetto
*   Gabriel Toffanetto França da Rocha
*   Universidade Federal de Itajubá - Campus Itabira
*   1068 - Balanco de Parênteses I
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string polinomio;
    int n;

    cin >> n;

    for(int i=0;i<n;i++){
        stack<char> parentesis_abre;
        stack<char> parentesis_fecha;
        cin>>ws;
        getline(cin,polinomio);
        for(int j=0;j<polinomio.size();j++){
            if(polinomio.at(j)=='(')
                parentesis_abre.push('(');
                else if(polinomio.at(j)==')'){
                    parentesis_fecha.push(')');
                    if(!parentesis_abre.empty()){
                        if(polinomio.at(j) != parentesis_abre.top()){
                            parentesis_abre.pop();
                            parentesis_fecha.pop();
                        }
                    }
                }
        
        }
        if(parentesis_abre.empty() && parentesis_fecha.empty())
            cout << "correct" << endl;
            else
                cout << "incorrect" << endl;            
    }
}