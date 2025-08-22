#include <iostream>
using namespace std;

long long int fibonacci[10000];
long long int fibo(int x){
    if(fibonacci[x] != -1){
        return fibonacci[x];
    }
    if(x == 0){
        fibonacci[x] = x;
        return 0;
    }
    if(x==1){
        fibonacci[x] = x;
        return 1;
    }
    fibonacci[x] = fibo(x-1) + fibo(x-2);
    return fibonacci[x];
}
void inicializaVetor(){
    for(int i = 0;i<10000;i++){
        fibonacci[i] = -1;
    }
}
int main(){
    inicializaVetor();
    int n;
    cin >> n;
    cout << fibo(n) << endl;

    return 0;
}