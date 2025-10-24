// Algoritmo de Busca Binária Iterativo

#include <iostream>
using namespace std;

int buscaBinaria(int v[], int l, int r, int x) {
    while (l <= r){
        int m = (l + r) / 2;
        if (v[m] == x){
            cout << "r = " << r << " e m = " << m << endl;
            return m;
        } else if (v[m] > x) {
            cout << "r = " << r << " e m = " << m << endl;
            r = m - 1;
        } else {
            cout << "r = " << r << " e m = " << m << endl;
            l = m + 1;
        }
        }
    return -1;
}
    

int main () {
    int v[] = {0, 0, 1, 1, 1, 3, 5, 9, 15, 25, 26, 27, 50, 51}; 
    int n = sizeof(v) / sizeof(v[0]);
    int x = 9;
    
    int resultado = buscaBinaria(v, 0, n - 1, x);

    if (resultado != -1) {
        cout << "Elemento encontrado no índice: " << resultado << endl;
    } else {
        cout << "Elemento nao encontrado." << endl;
    }

    return 0;
}
