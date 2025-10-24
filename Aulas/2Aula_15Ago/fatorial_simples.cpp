#include <iostream>
using namespace std;

int fat(int x){
    if(x == 0) //caso base
        return 1;
    return x*fat(x-1);
}
// Complexidade: O(N*M)
int main(){

    int M;
    cin >> M;
    while(M--){
        cout << "Informe o número" << endl;
        int N;
        cin >> N;
        cout << fat(N) << endl;
    }
    
    return 0;
}