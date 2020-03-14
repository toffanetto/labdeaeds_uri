#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;

    do{
        cin >> n;
        if(n==0)
            return 0;

        int aux;
        int num = 1;
        bool vai=true;
        while(vai){
            bool da = true;
            stack<int> p;

            for(int i=0;i<n;i++){
                cin >> aux;
                p.push(aux); 
            }
            while(!p.empty()){
                
            }
        }
    }while(n!=0);


}
