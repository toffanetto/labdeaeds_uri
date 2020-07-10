/*  @toffanetto
*   Gabriel Toffanetto França da Rocha
*   Universidade Federal de Itajubá - Campus Itabira
*   
*/

#include <iostream>
#include <set>

using namespace std;

int main(){
    int n;
    cin>>n;
    cin>>ws;
    for(int i=0;i<n;i++){
        string str,space="";
        set<string> lista;
        
        getline(cin,str);
        int last_space =0;
        for(int i=0;i<str.size();i++){
            if(str.at(i)==' ' || i==str.size()){
                string str1=str.substr(last_space,i);
                if(lista.find(str1)==lista.end())
                    lista.insert(str1);

                last_space=i+1;
            }
        }
        
        for(const auto& item:lista){
            cout << space << item;
            space=" ";
        }
        cout << endl;
    }
}