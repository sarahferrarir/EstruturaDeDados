#include <iostream>
using namespace std;

//tipo retorno nome_funcao (cnj parametros tipos)
bool par(int x){
    if(x % 2){
        return false;
    }
    return true;
}

int main(){
    int x;
    cin >> x; 
    cout << par(x) << endl;

    return 0;
}