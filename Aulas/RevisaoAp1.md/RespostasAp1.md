1)a) Verdadeira.  
b) Falso.   
c) Verdadeira.  
d) Verdadeira.     
e) Falso.   

2)  

3) Significa que a complexidade de tempo é equivalente ao cubo do tamanho de entrada. Por exemplo, em um algoritmo com O(n), o maior tempo possível sempre será proporcional ao tamanho da entrada, enquanto o O(nˆ3) demorará n * n * n (n ao cubo), ou seja, é muito menos eficiente.

4) (a) Qual é a complexidade temporal do algoritmo iterativo que calcula o fatorial de n?
A complexidade temporal do algoritmo iterativo para calcular o fatorial de n é O(n) (leitura: "ordem de n").

Isso acontece porque o algoritmo executa um laço de repetição, como um for ou while, que vai de 1 até n (ou de n até 1). A cada iteração, ele realiza um número constante de operações (uma multiplicação). Como o número de iterações é diretamente proporcional ao valor de n, a complexidade do tempo de execução é linear em relação a n.

(b) Existe uma diferença de complexidade entre o algoritmo iterativo e o recursivo para calcular o fatorial? Explique.
Não há diferença na complexidade temporal entre o algoritmo iterativo e o recursivo para o cálculo do fatorial. Ambos possuem complexidade O(n).

No entanto, há uma diferença significativa na complexidade de espaço (memória) e no desempenho prático:

Algoritmo Iterativo: A complexidade de espaço é O(1) (constante). Ele utiliza apenas algumas variáveis para armazenar o resultado e o contador do laço, independentemente do valor de n. Não há chamadas de função adicionais que consomem memória na pilha de chamadas.

Algoritmo Recursivo: A complexidade de espaço é O(n). Cada chamada recursiva ao fatorial(n-1) cria um novo quadro na pilha de chamadas para armazenar os parâmetros e variáveis locais. Para calcular o fatorial de n, a função é chamada n vezes, empilhando n quadros. Isso pode levar a um erro de "stack overflow" (estouro de pilha) para valores grandes de n, pois a memória da pilha é limitada.

Em resumo, embora a complexidade temporal seja a mesma, o algoritmo iterativo é mais eficiente em termos de uso de memória e geralmente tem um desempenho um pouco melhor na prática devido à sobrecarga das chamadas de função recursivas.

(c) Implemente os dois algoritmos para o cálculo do fatorial (iterativo e recursivo).
Abaixo estão as implementações em C++ para os dois algoritmos:

```C++

#include <iostream>

// Algoritmo Iterativo
long long fatorialIterativo(int n) {
    // Fatorial de 0 e 1 é 1.
    if (n < 0) {
        return -1; // Ou lançar uma exceção para números negativos
    }
    if (n == 0 || n == 1) {
        return 1;
    }

    long long resultado = 1;
    for (int i = 2; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

// Algoritmo Recursivo
long long fatorialRecursivo(int n) {
    // Caso base: o ponto de parada da recursão
    if (n == 0 || n == 1) {
        return 1;
    }
    // Caso recursivo: a chamada para a função com um problema menor
    return n * fatorialRecursivo(n - 1);
}

int main() {
    int numero = 5;

    // Teste do algoritmo iterativo
    std::cout << "Fatorial de " << numero << " (iterativo) = " << fatorialIterativo(numero) << std::endl;

    // Teste do algoritmo recursivo
    std::cout << "Fatorial de " << numero << " (recursivo) = " << fatorialRecursivo(numero) << std::endl;

    return 0;
}
```
