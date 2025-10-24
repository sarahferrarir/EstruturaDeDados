// Ideia principal: em cada iteração, procura o menor elemento no restante do array e coloca-o na posição correta trocando com o elemento atual.
// A cada passo, a parte inicial do array fica ordenada.
// Complexidade: sempre O(n²), independentemente da ordem inicial.
// Uso: Simples de implementar, mas menos eficiente do que insertion sort em casos práticos.
#include<iostream>
#include<vector>
using namespace std;

// Função para ordenar o vetor usando Selection Sort
void selectionSort(vector<int>& arr) {
    // Loop externo: percorre cada posição do vetor até a penúltima
    for (int i = 0; i < 4; i++) {
        int menor = i; // Assume que o menor elemento está na posição atual (i)
        
        // Loop interno: procura o menor elemento no restante do vetor
        for (int j = i + 1; j < 5; j++){
            if (arr[j] < arr[menor]){  // Se encontrar um elemento menor
                menor = j;             // Atualiza a posição do menor
            }
        }
        
        // Se o menor elemento não estiver na posição correta (i), faz a troca
        if (menor != i) {
            // swap(arr[i], arr[menor]);  // Outra forma de trocar
            // Implementando a troca manualmente:
            int k = arr[i];        // Guarda o valor de arr[i] em uma variável temporária
            arr[i] = arr[menor];   // Coloca o valor do menor na posição i
            arr[menor] = k;        // Coloca o valor temporário na posição do menor
        }
    }
}

int main() {
    // Declara e inicializa um vetor com 5 elementos
    vector<int> num = {5, 3, 8, 4, 2};

    // Chama a função de ordenação
    selectionSort(num);

    // Imprime o vetor já ordenado
    cout << "Array ordenado:  ";
    for (int n : num) cout << n << " ";  // Percorre e imprime cada elemento
    cout << endl;

    return 0; 
}
