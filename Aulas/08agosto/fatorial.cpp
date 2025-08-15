#include <iostream>
using namespace std;

int fatorial(int x){
    if(x == 0){
        return 1;
    }
    return fatorial(x-1)*x;
}

int main(){

    cout << fatorial(5) << endl;

    return 0;
}
