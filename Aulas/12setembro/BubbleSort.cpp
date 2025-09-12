#include <iostream>
using namespace std;

int main() {
    int V[8] = {1, 23, 5, 10, 5, -1, -2, 0};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            if (V[j] > V[j+1]) { 
                int aux = V[j];
                V[j] = V[j+1];
                V[j+1] = aux;
            }
        }
    }
    cout << "Vetor ordenado: ";
    for (int i = 0; i < 8; i++) {
        cout << V[i] << " ";
    }
    cout << endl;

    return 0;
} 
