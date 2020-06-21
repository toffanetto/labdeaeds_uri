/*  @toffanetto
*   Gabriel Toffanetto França da Rocha
*   Universidade Federal de Itajubá - Campus Itabira
*   2460 - Fila
*/

#include <iostream>
#include <list>

using namespace std;

int main(){
    int n,m;
    list<int> fila;
    cin >> n;
    for(int i=0;i<n;i++){
        int aux;
        cin>>aux;
        fila.push_back(aux);

    }
    cin >> m;
    for(int i=0;i<m;i++){
        int aux;
        cin >> aux;
        for(int j=0;j<n;j++){
            if(fila.front()==aux){
                fila.pop_front();
                j++;
                continue;
            }
            int frente = fila.front();
            fila.pop_front();
            fila.push_back(frente);
        }
    }

    cout << fila.front();
    fila.pop_front();

    while(!fila.empty()){
        cout << " " << fila.front();
        fila.pop_front();
    }
    cout << endl;
}
