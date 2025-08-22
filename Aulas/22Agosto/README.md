# Complexidade de Algoritmos

Por que analisar a complexidade de algoritmos?  
- O principal objetivo é projetar algoritmos **eficientes**;  
Um algoritmo pode ser desenvolvido e posteriormente analisado, mas o ideal é projetá-lo de forma eficiente desde a concepção.  
---
### Medição da Complexidade 

Questões importantes:   
- Como medir o custo de um algoritmo?   
- Como comparar diferentes algoritmos que resolvem o mesmo problema?  

Maneiras de medir a complexidade:  
 1. Medição direta do tempo de execução:  
        - Problema: depende do compilador, hardware e memória disponível.  
 2. Considerar um "computador ideal" (conforme Donald Knuth);
 3. Focar nas operações mais significativas (método mais usado):  
        - Exemplo: Em ordenação, contar o número de comparações.

---
### Função de Complexidade 

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

#### Custo de Comparações

Seja *f*(n) a função de complexidade:
- *f*(n) representa o número de comparações feitas em um vector A de tamanho n. 
- Para o algoritmo mostrado, podemos determinar que: ` f(n) = n - 1, para n > 0. `

---
### Complexidade Mínima
***Fato***: Qualquer algoritmo que encontra o maior elemento em um conjunto de *n* elementos precisa fazer pelo menos *n* − 1 comparações.  
***Conclusão***: Como o algoritmo *maxArray()* atinge esse limite inferior, ele é considerado um **algoritmo ótimo**.

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
---
### Crescimento Assintótico de Funções 
O custo da solução aumenta com o tamanho *n* do problema:
- O tempo necessário para resolver um problema cresce conforme *n* aumenta. 
   - Exemplo: O número de comparações para encontrar o maior elemento em um vetor (array) ou para ordená-lo aumenta com o tamanho da entrada *n*.  
A escolha do algoritmo não é crítica quando *n* é pequeno, por isso, é comum analisar o comportamento das funções de custo quando *n* é grande.

**Relacionamento Assintótico**   
Definição: Uma função *g(n)* domina assintoticamente outra função *f(n)* se existem constantes positivas *c* e *m* tais que, para *n* >= *m*, temos ` |f(n)| <= c|g(n)| `


[PPT slides](https://drive.google.com/file/d/1aYeHiFLVc059234THNeKK9vRoXNl01lP/view)
