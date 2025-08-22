# Complexidade de Algoritmos

Por que analisar a complexidade de algoritmos?  
- O principal objetivo é projetar algoritmos **eficientes**;  
Um algoritmo pode ser desenvolvido e posteriormente analisado, mas o ideal é projetá-lo de forma eficiente desde a concepção.  

## Medição da Complexidade 

Questões importantes:   
- como medir o custo de um algoritmo?   
- Como comparar diferentes algoritmos que resolvem o mesmo problema?  

Maneiras de medir a complexidade:  
 1. Medição direta do tempo de execução:  
 - problema: depende do compilador, hardware e memória disponível.  
 2. Considerar um computador ideal" (conforme Donald)  

## Função de Complexidade 

*Definição*: A função de complexidade *f*(n) mede o tempo ou espaço necessário para executar um algoritmo com entrada de tamanho n.
- se a medida é de tempo, chamamos de **complexidade temporal**;
- se a medida é de espaço, chamamos de **complexidade espacial**;
- se não especificado, assumimos *f*(n) como **complexidade de tempo**.


Exemplo de Complexidade: *Algoritmo maxArray*

```cpp
int maxArray(int A[], int size) {
    int max = A[0];
    for (int i = 1; i < size; ++i) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}
```

**Custo de Comparações**

Seja *f*(n) a função de complexidade:
- *f*(n) representa o número de comparações feitas em um vector A de tamanho n. 
- Para o algoritmo mostrado, podemos determinar que: 
*f*(n) = n - 1, para n > 0. 

## Complexidade Mínima

Exemplo Alternativo: *Algoritmo maxArray1*

```cpp
#include <iostream>
using namespace std;

void maxArray1(int A[]) {
    int max = A[0];
    int min = A[0];

    for (int i - 1; i < A.size(); ++i) {
        if (max < A[i]) {
            max = A[i];
        } else if (A[i] < min) {
            min = A[i];
        }
    }

    cout << "Mínimo = " << min << endl;
    cout << "Máximo = " << max << endl;
}
```