/*  @toffanetto
*   Gabriel Toffanetto França da Rocha
*   Universidade Federal de Itajubá - Campus Itabira
*   1244 - Ordenação por Tamanho 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, string> par;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        
        vector<par> palavras;
        vector<int> espacos;
        string linha;

        cin >> ws;
        getline(cin, linha);

        for(int j=0;j<linha.size();j++){
            if(linha.at(j)==' ')
                espacos.push_back(j);
        }

        string str = linha.substr(0,espacos.at(0)); //Primeiro
        int tam = str.size();
        palavras.push_back(make_pair(tam, str));

        for(int j=0;j<espacos.size();j++){

            if(j==espacos.size()-1){ //Ultimo
                string str = linha.substr(espacos.at(j)+1);
                int tam = str.size();
                palavras.push_back(make_pair(tam, str));
            } 
                else{ // meio
                    string str = linha.substr(espacos.at(j)+1,(espacos.at(j+1)-espacos.at(j)-1));
                    int tam = str.size();
                    palavras.push_back(make_pair(tam, str));    
                }
        }

        sort(palavras.begin(),palavras.end(), [](const par& x, const par& y){ return x.first > y.first; });


        for(int j=0;j<palavras.size();j++){

            cout << palavras.at(j).second;

            if(j!=palavras.size()-1)
                cout << " ";
        }

        cout << endl;

    }
}