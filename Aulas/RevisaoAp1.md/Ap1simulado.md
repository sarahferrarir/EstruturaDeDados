# 1 Complexidade de Algoritmos
**1.** (2.5 Pontos) Determine se as afirmações abaixo são verdadeiras (V) ou falsas (F) em relação à
álise de complexidade de algoritmos:

**(a)** A notação O(f(n)) representa um limite superior assintótico para o tempo de execução de um algoritmo. 
- (Verdadeiro)
- Por exemplo, um algoritmo com complexidade de O(nˆ2), levará, no pior caso, o quadrado de sua entrada.


**(b)** O tempo de execução de um algoritmo com complexidade O(nˆ3) é sempre maior do que o de um algoritmo com complexidade O(n), independentemente do tamanho de n. 
- (Falso)
- A afirmação é falsa pois não podemos afirmar isso sem saber o tamanho de n, por exemplo, se a entrada do algoritmo O(nˆ3) for pequena e a de O(n) for grande, (por exemplo, 2 e 100 respectivamente) então O(n) será maior.


**(c)** O pior caso de um algoritmo representa o cenário em que o tempo de execução é maximizado para o tamanho da entrada considerada. 
- (Verdadeiro)
- Pois quando calculamos a complexidade de tempo, é essencial saber qual seria o tempo máximo que o algoritmo poderia levar, ou seja, qual seria o pior caso.


**(d)** O tempo de execução de um algoritmo com complexidade O(1) é constante, independentemente do tamanho da entrada.
- (Verdadeiro)
- Pois a complexidade O(1) não tem relação com a entrada, sempre será 1. 


**(e)** Para dois algoritmos A e B, se A tem complexidade O(nlogn) e B tem complexidade O(nˆ2), então A será mais rápido que B para todos os valores de n. 
- (Falso)
- Apesar do algoritmo O(nlogn) ser mais rápido e eficiente do que O(nˆ2), isso não significa que ele será mais rápido para todos os valores de n.  
--- 

**2.** (1 Ponto) Algoritmos e Estrutura de Dados   
Considere um vetor ordenado em ordem crescente com tamanho teoricamente infinito, ou seja, não é possível determinar diretamente seu tamanho ou seu último índice válido. Seu objetivo é desenvolver um algoritmo eficiente para encontrar a posição (índice) de um determinado valor nesse vetor. Assuma que o acesso a qualquer posição do vetor retorna o valor naquela posição caso a posição exista, ou retorna um valor especial indicando que a posição é inválida (por exemplo, infinito).

**a)** Descreva claramente a lógica e o funcionamento do algoritmo proposto.  
- Como é um vetor ordenado, o ideal seria utilizar Busca Binária, mas para isso preciso saber os limites do vetor. Então antes disso, vou desenvolver um algoritmo para encontrar o intervalo necessário para busca binária. Em etapas:
    - começar com um índice pequeno;
    - verificar se o valor está dentro do intervalo, se não está, dobrar o índice para aumentar o tamanho do intervalo;
    - loop que continua dobrando o índice, até que seu valor seja maior do que valor que quero encontrar;
    - determina então que o valor está no intervalo entre índice anterior e o último índice do loop.
- Depois de obter esse intervalo, aplico o algoritmo de busca binária, ou seja, um loop que divide o intervalo no meio até encontrar o valor desejado, ou determinar que ele não existe no vetor.


**b)** Implemente, utilizando pseudocódigo, o algoritmo descrito na letra (a).  
```cpp
#include <iostream>
#include <vector>
using namespace std;

// 1 passo: Definir uma constante para simular o valor "infinito"
const int INFINITY_VAL = 2147483647;

// 2 passo: declarar o vetor que simula o vetor "infinito".
vector<int> vetorInfinito = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41};

// 3 passo: Função que simula o acesso a um vetor infinito.
int acessar(int indice) {
    if (indice >= vetorInfinito.size()) {
        return INFINITY_VAL; // Retorna nosso valor de infinito
    }
    return vetorInfinito[indice];
}

// 4 passo: Implementar a Busca Binária em um intervalo específico
int buscaBinaria(int inicio, int fim, int valor) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        int valorDoMeio = acessar(meio);

        if (valorDoMeio == valor) {
            return meio;
        } else if (valorDoMeio < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

// 5 passo: Algoritmo principal que encontra a posição do valor
int encontrarPosicao(int valor) {
    if (acessar(0) == valor) {
        return 0;
    }

    // Etapa 1: Busca Exponencial para encontrar o intervalo
    int indice = 1;
    while (acessar(indice) < valor) {
        indice *= 2;
    }

    // Etapa 2: Aplica a Busca Binária no intervalo encontrado
    return buscaBinaria(indice / 2, indice, valor);
}

int main() {
    int valorBuscado = 27;
    int resultado = encontrarPosicao(valorBuscado);

    if (resultado != -1) {
        cout << "O valor " << valorBuscado << " foi encontrado no indice " << resultado << "." << endl;
    } else {
        cout << "O valor " << valorBuscado << " nao foi encontrado." << endl;
    }

    int valorNaoEncontrado = 10;
    resultado = encontrarPosicao(valorNaoEncontrado);

    if (resultado != -1) {
        cout << "O valor " << valorNaoEncontrado << " foi encontrado no indice " << resultado << "." << endl;
    } else {
        cout << "O valor " << valorNaoEncontrado << " nao foi encontrado." << endl;
    }

    return 0;
}
```
**c)** Determine a complexidade computacional do algoritmo proposto em termos de tempo, justificando sua resposta.  
- Esse algoritmo é a junção de dois algoritmos com complexidade de tempo de O(logn). Como a busca exponencial está sempre dobrando o índice, e a binária divindo o intervalo no meio, a complexidade é logarítmica em relação à n.
- Então, o algoritmo completo teria a complexidade de O(2logn), mas na notação big O, constantes são ignoradas, ficando apenas como - O(logn). 

> Observação: O algoritmo proposto deve ser mais eficiente do que simplesmente percorrer sequencialmente o vetor elemento por elemento.
---

**3.** (1 Ponto) O que significa dizer que um algoritmo tem complexidade de tempo O(nˆ3)?  
> Dica: Demonstre o crescimento da função e compare com outras funções de complexidade de tempo.  

- Significa que a complexidade de tempo é equivalente ao cubo do tamanho de entrada. Por exemplo, em um algoritmo com O(n), o maior tempo possível sempre será proporcional ao tamanho da entrada, enquanto o O(nˆ3) demorará n * n * n (n ao cubo), ou seja, é muito menos eficiente.
---

**4.** (1 Ponto) Considere o problema de calcular o fatorial de um número n, definido como:  
`n! = n × (n − 1) × (n − 2) × · · · × 1`  
Responda às perguntas abaixo com base na análise de complexidade de algoritmos para o cálculo do fatorial:  


**(a)** Qual é a complexidade temporal do algoritmo iterativo que calcula o fatorial de n?
- O(n), pois o algoritmo executa o loop n vezes. Mesmo tendo uma multiplicação em cada iteração, isso não afeta a complexidade de tempo, o que afeta é o número de iterações. Por isso a complexidade será de O(n), pois leva tempo proporcional ao tamanho da entrada.

**(b)** Existe uma diferença de complexidade entre o algoritmo iterativo e o recursivo para calcular o fatorial? Explique.
- Não tem diferença de tempo, os dois levariam O(n). Mas existe diferença na complexidade de espaço. O algoritmo iterativo é mais eficiente, pois usa menos memória e normalmente tem um desempenho melhor do que o recursivo também. 
> Não há diferença na complexidade temporal entre o algoritmo iterativo e o recursivo para o cálculo do fatorial. Ambos possuem complexidade O(n). No entanto, há uma diferença significativa na complexidade de espaço (memória) e no desempenho prático:  
> - Algoritmo Iterativo: A complexidade de espaço é O(1) (constante). Ele utiliza apenas algumas variáveis para armazenar o resultado e o contador do laço, independentemente do valor de n. Não há chamadas de função adicionais que consomem memória na pilha de chamadas.  
> - Algoritmo Recursivo: A complexidade de espaço é O(n). Cada chamada recursiva ao fatorial(n-1) cria um novo quadro na pilha de chamadas para armazenar os parâmetros e variáveis locais. Para calcular o fatorial de n, a função é chamada n vezes, empilhando n quadros. Isso pode levar a um erro de "stack overflow" (estouro de pilha) para valores grandes de n, pois a memória da pilha é limitada.

> Em resumo, embora a complexidade temporal seja a mesma, o algoritmo iterativo é mais eficiente em termos de uso de memória e geralmente tem um desempenho um pouco melhor na prática devido à sobrecarga das chamadas de função recursivas.

**(c)** Implemente os dois algoritmos para o cálculo do fatorial (iterativo e recursivo).

```cpp
#include<iostream>
using namespace std;

int fatorialRecursivo(int x) {
    if (x == 0) {
        return 1;
    }

    return fatorialRecursivo(x - 1) * x;
}

int fatorialIterativo(int x) {
    long long fat = 1;

    for (int i = 2; i <= x; ++i) {
        fat *= i; 
    }
    
    return fat;
}

int main () {
    cout << fatorialRecursivo(5) << endl;
    cout << fatorialIterativo(5) << endl;
 
    return 0;
}
```

--- 
**5.** (1 Pontos) Determine a complexidade de tempo do código abaixo e explique.

```cpp
void func (int n ) {
    for (int i = 1; i < n ; i *= 2) {
        std :: cout << i << std :: endl ;
    }
}
```
- Terá complexidade de O(n), pois o algoritmo executa um loop for, que terá n interações. Logo, sua complexidade temporal será linear ao tamanho da entrada.
--- 

**6.**(1.5 Pontos ) Considere o seguinte código em C++ que realiza a multiplicação de duas matrizes A e B, ambas de dimensão n × n:
```cpp
void multiplica ( int A [][100] , int B [][100] , int C [][100] , int n ) {
    for (int i = 0; i < n ; i ++) {
        for (int j = 0; j < n ; j ++) {
            C [ i ][ j ] = 0;
            for (int k = 0; k < n ; k ++) {
                C [ i ][ j ] += A [ i ][ k ] * B [ k ][ j ];
            }
        }
    }
}
```

**(a)** Qual é a complexidade temporal do algoritmo de multiplicação de matrizes implementado no código acima?  
- Tem complexidade de O(nˆ3), pois existem 3 loops no algoritmo, um dentro do outro. Ou seja, para cada 1 iteração do loop externo, o do meio executa n vezes, e, igualmente, para 1 iteração do loop do meio, o mais interno também executará n vezes. Logo, o tempo total será de n * n * n   ->   O(nˆ3).


**(b)** Se as matrizes fossem de dimensões `n * m` e `m * p`, como a complexidade seria afetada?  
- A complexidade para a multiplicação de uma matriz A de dimensão n×m por uma matriz B de dimensão m×p seria O(n×m×p). O algoritmo de multiplicação de matrizes exige que o número de colunas da primeira matriz (m) seja igual ao número de linhas da segunda (m), resultando em uma matriz C de dimensão n×p.
- A complexidade é calculada multiplicando o número de iterações de cada laço, resultando em n×p×m.

**(c)** Explique o que aconteceria com se n dobrasse. Como isso impactaria o número total de operações?
- O algoritmo ficaria 8 vezes maior. A complexidade original é O(nˆ3), se n dobrasse, ficaria O((2n)ˆ3), que é equivalente a O(8nˆ3).

# 2 Ordenação
**(a)** (1 Ponto) Implemente um algoritmo de ordenação qualquer (a sua escolha) e ordene o seguinte vetor:   
`3, −1, 2, 5, 12, 7, 5, 4, 9, −3;`   
Demonstre passo a passo e explique a complexidade do algoritmo escolhido.

--- 
**(b)** (1 Ponto) Descreva em que circunstâncias é mais vantajoso escolher o Selection Sort em vez do Bubble Sort ou do Insertion Sort. Comente sobre os motivos dessa escolha.
