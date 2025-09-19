// Ideia principal: comparar pares de elementos adjacentes e trocar se estiverem na ordem errada.
// A cada passada, o maior elemento “borbulha” para o final do array.
// Complexidade: O(n²) no pior e médio caso, O(n) no melhor caso (quando o array já está ordenado e você otimiza parando cedo).
// Uso: Simples de entender, mas pouco eficiente para grandes listas.
#include <iostream>
using namespace std;

int main() {
    // Declaração e inicialização do vetor com 8 elementos
    int V[8] = {1, 23, 5, 10, 5, -1, -2, 0};

    // Algoritmo Bubble Sort
    // Dois loops aninhados: percorrem o vetor e realizam trocas
    for (int i = 0; i < 8; i++) {          // Loop externo: controla quantas vezes o vetor será percorrido
        for (int j = 0; j < 7; j++) {      // Loop interno: compara elementos adjacentes
            if (V[j] > V[j+1]) {           // Se o elemento atual for maior que o próximo
                // Troca os elementos de posição
                int aux = V[j];
                V[j] = V[j+1];
                V[j+1] = aux;
            }
        }
    }

    // Impressão do vetor já ordenado
    cout << "Vetor ordenado: ";
    for (int i = 0; i < 8; i++) {
        cout << V[i] << " ";   // Exibe cada elemento do vetor
    }
    cout << endl;

    return 0;  
}
