// Ideia principal: constrói a parte ordenada do array gradualmente.
// Para cada elemento, insere-o na posição correta da porção já ordenada, deslocando elementos maiores para a direita.
// Complexidade: O(n²) no pior caso, mas O(n) se o array já estiver quase ordenado.
// Uso: Muito bom para arrays pequenos ou quase ordenados. É estável e in-place.
#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < 5; i++) {
        int elemento = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > elemento) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = elemento;
    }
}

int main() {
    vector<int> num = {3, 5, -1, 0, 2};

    insertionSort(num);

    cout << "Array ordenado:  ";
    for (int n : num) cout << n << " ";
    cout << endl;

    return 0;
}

