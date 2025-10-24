// Ideia principal: constrói a parte ordenada do array gradualmente.
// Para cada elemento, insere-o na posição correta da porção já ordenada, deslocando elementos maiores para a direita.
// Complexidade: O(n²) no pior caso, mas O(n) se o array já estiver quase ordenado.
// Uso: Muito bom para arrays pequenos ou quase ordenados. É estável e in-place.
#include<iostream>
#include<vector>
using namespace std;

// Função para ordenar o vetor usando Insertion Sort
void insertionSort(vector<int>& arr) {
    // Começa no índice 1, porque consideramos o primeiro elemento já "ordenado"
    for (int i = 1; i < 5; i++) {
        int elemento = arr[i];  // O elemento que queremos inserir na posição correta
        int j = i - 1;          // Índice do último elemento da parte já ordenada
        
        // Enquanto ainda estivermos dentro da parte ordenada (j >= 0)
        // e o elemento em arr[j] for maior do que o elemento que queremos inserir,
        // vamos "empurrar" arr[j] uma posição à direita
        while (j >= 0 && arr[j] > elemento) {
            arr[j + 1] = arr[j];  // Move arr[j] para frente
            j--;                  // Vai para o elemento anterior
        }
        
        // Quando a posição correta for encontrada, insere o elemento
        arr[j + 1] = elemento;
    }
}

int main() {
    // Declara e inicializa um vetor com 5 elementos
    vector<int> num = {3, 5, -1, 0, 2};

    // Chama a função de ordenação
    insertionSort(num);

    // Imprime o vetor ordenado
    cout << "Array ordenado:  ";
    for (int n : num) cout << n << " ";  // Percorre cada elemento e imprime
    cout << endl;

    return 0; 
}


