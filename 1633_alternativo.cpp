/*  @toffanetto
*   Gabriel Toffanetto França da Rocha
*   Universidade Federal de Itajubá - Campus Itabira
*   1633 - SBC
*/

#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    while(cin >> n){

        uint64_t tempo=0;
        int t,c;
        vector<int> ciclos (100000);
        queue<pair<int,int>> programas; // <tempo de chegada,tempo em espera>

        for(int i=0;i<n;i++){
            cin >> t >> c;
            ciclos.at(t)=c;
            programas.push(make_pair(t,0));
        }
/*
        for(int i=0;i<n;i++){
            int id = programas.front().first;
            cout << "---" << id << "   " << ciclos.at(id) << endl;
            programas.pop();
            programas.push(make_pair(id,0));
        }
*/
        int clock=1;

        while(!programas.empty()){
            cout << "---ON Ciclo " << clock;
            t=programas.front().first;
            c=ciclos.at(t);
            clock+=c;
            cout << "--- ESPERANDO " << programas.front().second;
            tempo+=programas.front().second;
            programas.pop();
            cout << " ID " << t<< " C " << c << endl;
            for(int i=0;i<programas.size();i++){
                int id = programas.front().first;
                programas.pop();
                if(id<clock){
                    int esperando =(clock-id-t);
                    programas.push(make_pair(id,esperando));
                }
                    else 
                        programas.push(make_pair(id,0));
            }
        }

        cout << tempo << endl;
    }
}

