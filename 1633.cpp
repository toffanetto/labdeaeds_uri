/*  @toffanetto
*   Gabriel Toffanetto França da Rocha
*   Universidade Federal de Itajubá - Campus Itabira
*   1633 - SBC
*/

#include <iostream>
#include <queue>

using namespace std;

class Programa{
public:
    int tempo_chegou;
    int tempo_executando;

    Programa(int tempo_chegou, int tempo_executando){
        this->tempo_chegou = tempo_chegou;
        this->tempo_executando = tempo_executando;
    }
    ~Programa(){};
    bool operator<(const Programa&) const;
};

bool Programa::operator<(const Programa& p) const{
    if(p.tempo_executando==tempo_executando)        // Não sei oq comparar aqui
        return p.tempo_chegou<tempo_chegou;
        else
            return p.tempo_executando<tempo_executando; 
}
int main(){
    int n;
    while(cin >> n){

        uint64_t tempo=0;
        int t, c, clock=1, executando=0;
        priority_queue<Programa> programas;

        for(int i=0;i<n;i++){
            cin >> t >> c;
            programas.push(Programa(t,c));
            if(clock<programas.top().tempo_chegou){
                clock++;
                continue;
            }
            if(executando==0){
                Programa task = programas.top();
                programas.pop();
                //cout << "TEMPO " << clock << " TEMPO PROGRAMA " << task.tempo_chegou << endl;
                tempo+= (clock>task.tempo_chegou) ? (clock-task.tempo_chegou) : 0;
                executando=task.tempo_executando;
            }
            clock++;
            executando--;
        }

        while(!programas.empty()){
            if(clock<programas.top().tempo_chegou){
                clock++;
                continue;
            }
            if(executando==0){
                Programa task = programas.top();
                programas.pop();
                //cout << "TEMPO " << clock << " TEMPO PROGRAMA " << task.tempo_chegou << endl;
                tempo+= (clock>task.tempo_chegou) ? (clock-task.tempo_chegou) : 0;
                executando=task.tempo_executando;
            }
        clock++;
        executando--;
        }
        cout << tempo << endl;
    }
}