# Lista de Exercícios – Complexidade de Algoritmos
Questões e Exercícios sobre Complexidade Computacional.

## Questões Teóricas

1) **Defina o conceito de complexidade de tempo de um algoritmo.**  
A complexidade de tempo de um algoritmo é a análise do tempo necessário para a execução desse algoritmo.

2) **O que significa dizer que um algoritmo tem complexidade de tempo O(n²)?**  
Significa que o algoritmo leva, no pior caso, tempo proporcional ao quadrado do tamanho da entrada.

3) **Se um algoritmo tem complexidade de tempo O(1), como seu tempo de execução varia em relação ao tamanho da entrada?**  
No caso de O(1), o tempo de execução não depende do tamanho da entrada.

4) **Qual é a diferença entre as notações O(n) e Ω(n) na análise de algoritmos?**  
- O(n) fornece um limite superior (pior caso).  
- Ω(n) fornece um limite inferior (melhor caso).

5) **Dê um exemplo de um algoritmo que tenha complexidade de tempo O(n log n).**  
O Merge Sort é um algoritmo de ordenação eficiente: o array é dividido recursivamente em duas metades até sobrar apenas um elemento; em seguida, os subarrays ordenados são unidos (merge) em um array maior. É usado principalmente para grandes listas ou conjuntos de dados.

6) **Se um algoritmo tem complexidade de espaço O(n), o que isso nos diz sobre o uso de memória desse algoritmo?**  
O uso de memória é proporcional ao tamanho da entrada (n).

7) **Explique a importância de considerar a complexidade de tempo ao escolher um algoritmo para resolver um problema.**  
É importante para escolher algoritmos mais eficientes e de menor custo, garantindo execução rápida mesmo com grandes entradas.

8) **Qual é a complexidade de tempo de uma busca linear em uma lista desordenada? Justifique.**  
A complexidade é O(n), pois no pior caso o algoritmo precisa passar por todos os elementos da lista desordenada.

9) **O que significa dizer que a complexidade de tempo de um algoritmo é O(n!)? Dê um exemplo de problema com essa complexidade.**  
Significa que o tempo de execução cresce proporcional ao fatorial do tamanho da entrada. Exemplo: algoritmo de permutação de conjuntos de dados. Entrada de tamanho 3 → 3! = 6 combinações → complexidade O(n!).

10) **Se um Algoritmo A tem complexidade de tempo O(n) e outro algoritmo B tem complexidade de tempo O(n²), qual é a principal diferença em termos de eficiência?**  
O(n) é mais eficiente, pois o tempo máximo cresce linearmente com a entrada, enquanto O(n²) leva tempo proporcional ao quadrado do tamanho da entrada, sendo mais custoso.

## Exercícios Práticos em C++

1) **Considere o código C++ abaixo. Qual é a complexidade de tempo do algoritmo? Justifique.**  
```cpp
void exemplo1(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << i << std::endl;
    }
}
```
Resposta: a complexidade de tempo será O(n), pois será proporcional ao tamanho da entrada.

2) **Analise o código abaixo. Qual é a complexidade de tempo e por quê?**
```cpp
void exemplo2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << i * j << std::endl;
        }
    }
}
```
Resposta: O(n²), pois o loop externo executa n vezes e, para cada iteração, o loop interno também executa n vezes. Total de execuções: n * n → O(n²).    

3) **Determine a complexidade de tempo do código abaixo e explique.**
```cpp
void exemplo3(int n) {
    for (int i = 1; i < n; i *= 2) {
        std::cout << i << std::endl;
    }
}
```
Resposta: O(log n), pois a cada iteração o valor de i dobra, ou seja, o número de iterações é proporcional ao logaritmo de n.  

4) **O código abaixo implementa uma busca binária. Qual é a complexidade de tempo? Explique sua análise.**
```cpp
int buscaBinaria(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
```
Resposta: O(log n), pois a cada iteração metade do espaço de busca é descartado, reduzindo significativamente o número de comparações.  

5) **Para o código abaixo, qual é a complexidade de tempo? Justifique sua resposta.**
```cpp
void exemplo5(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << i + j << std::endl;
        }
    }
}
```
Resposta: O(n²), pois o loop interno roda n vezes para cada execução do loop externo, que também é executado n vezes, resultando em um número total de operações proporcional a n².

