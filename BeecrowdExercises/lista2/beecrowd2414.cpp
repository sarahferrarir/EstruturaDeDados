//Title: Desafio do Maior Número

#include <iostream>
using namespace std;

int main() {
    int num, maior = 0;

    while (true) {
        cin >> num;  
        if (num == 0) break; 
        if (num > maior) {
            maior = num; 
        }
    }

    cout << maior << endl; 
    return 0;
}
