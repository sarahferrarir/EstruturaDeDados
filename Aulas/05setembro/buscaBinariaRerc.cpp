// Algoritmo de Busca Binária Recursivo

#include <iostream>
using namespace std;

int buscaBinariaRec(int v[], int l, int r, int x) {
    if (l > r) { 
        return -1; 
    }

    int m = (l + r) / 2; 
    cout << "r = " << r << " e m = " << m << endl; 

    if (v[m] == x) {
        return m; 
    } 
    else if (x < v[m]) {
        return buscaBinariaRec(v, l, m - 1, x); 
    } 
    else {
        return buscaBinariaRec(v, m + 1, r, x); 
    }
}

int main() {
    int v[] = {0, 0, 1, 1, 1, 3, 5, 9, 15, 25, 26, 27, 50, 51}; 
    int n = sizeof(v) / sizeof(v[0]);
    int x;

    cout << "Digite o valor que deseja procurar: ";
    cin >> x;

    int resultado = buscaBinariaRec(v, 0, n - 1, x);

    if (resultado != -1) {
        cout << "Elemento encontrado no índice: " << resultado << endl;
    } else {
        cout << "Elemento nao encontrado." << endl;
    }

    return 0;
}
