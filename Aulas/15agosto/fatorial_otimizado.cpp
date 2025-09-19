#include <iostream>
using namespace std;

long long int fatorial[100001];

long long int fat(int x){
    if(x == 0){ //caso base
        fatorial[x] = 1;
        return fatorial[x];
    }
    fatorial[x] = x*fat(x-1);
    return fatorial[x];
}
// Complexidade: O(N+M)
int main(){
    fat(100000);
    int M;
    cin >> M;
    while(M--){
        cout << "Informe o número" << endl;
        int N;
        cin >> N;
        cout << fatorial[N] << endl;
    }
    
    return 0;
}
