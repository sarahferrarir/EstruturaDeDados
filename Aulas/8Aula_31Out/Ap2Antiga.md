# Listas Encadeadas

## 1. Questão de Vantagens e Desvantagens (0.5 PONTO)   
As afirmativas corretas são 1, 2 e 4.  
> Alternativa Correta: B) Somente as afirmativas 1, 2 e 4 estão corretas.

Justificativa:  
- (a) Listas encadeadas permitem alocação dinâmica de memória, sendo eficientes no uso de espaço quando comparadas a vetores. (CORRETA).
  
Listas crescem sob demanda (alocação dinâmica), evitando o desperdício de memória de vetores de tamanho fixo.   
- (b) Inserir ou remover elementos no início da lista encadeada é mais eficiente do que em vetores, pois não é necessário deslocar elementos. (CORRETA).
  
A inserção no início é $O(1)$ (apenas ajustando um ponteiro), enquanto em vetores é $O(N)$ (deslocamento de todos os elementos).   
- (c) A busca por um elemento em uma lista encadeada é, em geral, mais eficiente do que em vetores devido à sua estrutura sequencial. (INCORRETA).
  
A busca é $O(N)$ em listas e $O(1)$ em vetores (acesso direto/aleatório).  
- (d) Listas encadeadas exigem armazenamento adicional para os ponteiros, o que pode aumentar o consumo de memória em comparação a vetores. (CORRETA).
  
Cada nó tem um overhead de memória para armazenar o ponteiro.   
- (e) Em listas encadeadas, o acesso direto a elementos é rápido, permitindo consultas em tempo constante $O(1)$. (INCORRETA).
  
O acesso é sequencial, exigindo percorrimento (complexidade $O(N)$.

--- 

## 2. Questão de Complexidade em Lista Duplamente Encadeada (0.5 PONTO)
As afirmativas corretas são 1, 2, 4 e 5.   
> Alternativa Correta: C) Somente as afirmativas 1, 2, 4 e 5 estão corretas.

Justificativa:   
- (a) Inserir um elemento no início da lista possui complexidade $O(1)$. (CORRETA).    

Requer apenas a manipulação dos ponteiros prox e ant do novo nó e do nó cabeça.   
- (b) Inserir um elemento no final da lista possui complexidade $O(1)$, desde que seja mantido um ponteiro para o último nó. (CORRETA).   

O acesso ao último nó é direto, permitindo a inserção em tempo constante.
- (c) Remover um elemento de uma posição específica na lista possui complexidade $O(1)$, independentemente da posição. (INCORRETA).   

A remoção só é $O(1)$ se já tivermos o ponteiro para o nó (ou o nó anterior); caso contrário, a busca pela posição é $O(N)$.   
- (d) A busca por um elemento na lista possui complexidade $O(n)$ no pior caso. (CORRETA).  

É necessário percorrer toda a lista se o elemento não for encontrado ou se for o último.   
- (e) Inserir um elemento em uma posição intermediária na lista requer encontrar a posição primeiro, o que pode adicionar uma complexidade de $O(n)$ no pior caso. (CORRETA).   
A operação de inserção em si é $O(1)$, mas a busca torna a operação total $O(N)$.

---

## 3. Análise da Lista Duplamente Encadeada Circular (0.5 PONTOS)
Para esta questão, é necessário supor a estrutura básica Node com dado, prox e ant.  

- (a) Complete o método inserirFinal()   
O método deve inserir um novo nó antes do nó cabeça (head) e depois do último nó (head->ant).

```cpp
void ListaDuplamenteEncadeadaCircular::inserirFinal(int x) {
    // 1. Cria o novo nó
    Node *new_no = new Node(x); // Assumindo construtor com 'dado'
    
    // 2. O antigo último nó é 'head->ant'.
    Node *ultimo_no = head->ant;
    
    // 3. Conecta o novo nó ao antigo último (ant) e ao head (prox)
    new_no->prox = head;
    new_no->ant = ultimo_no;
    
    // 4. Ajusta os ponteiros dos nós vizinhos
    head->ant = new_no;      // O head aponta para o novo nó como seu anterior
    ultimo_no->prox = new_no; // O antigo último aponta para o novo nó como seu próximo
}
```

- (b) Complexidade do método buscar(int x)

A complexidade de tempo é $O(n)$ (Linear).

Justificativa: O método percorre a lista do início (head->prox) até que encontre o elemento (p->dado == x) ou até que o ponteiro p volte para a cabeça (p != head). 
No pior caso (elemento não existe ou é o último), o método deve visitar todos os $n$ nós da lista, tornando a complexidade proporcional ao número de elementos.

- (c) Comportamento do removerLista(int x) se o nó não for encontrado e melhorias

O que aconteceria se um nó não for encontrado: Se o valor x não for encontrado, o laço while terminará quando p se tornar o nó head (p != head será falso, embora o código fornecido esteja confuso). 
A linha if (p != head) será falsa, e o código sairá do método sem tentar liberar memória, o que está correto (não causa erro de memória, mas é ineficiente na busca).

O que poderia ser melhorado para tornar o método mais eficiente: O método percorre a lista duas vezes: uma no while (para encontrar o nó) e uma implicitamente no percurso de p = p->prox que está fora do while. 
A melhoria de eficiência não está na complexidade (que é $O(N)$), mas sim na implementação e clareza do código C++: o percurso e a busca devem estar contidos em um único laço.

- (d) Problema no método imprimir()

Problema Identificado: O método imprimir() é um laço infinito.

```cpp
// Código original:
while (p != head) {
    cout << p->dado << endl;
    // Falta o avanço do ponteiro p = p->prox;
}
```
Justificativa e Correção: O ponteiro p nunca é atualizado dentro do laço while. 
O valor de p permanece head->prox, e a condição p != head nunca se torna falsa (a menos que a lista esteja vazia).

Correção: Adicionar o avanço do ponteiro p = p->prox; dentro do laço.

```cpp
void imprimir() {
    Node *p = head->prox;
    while (p != head) {
        cout << p->dado << endl;
        p = p->prox; // <--- CORREÇÃO AQUI
    }
}
```

--- 

## 4. Questão sobre Operações em Pilha (0.5 PONTO)
Alternativa Correta: (b) A operação pop() em uma Pilha remove o elemento do topo e tem complexidade $O(1)$, pois o acesso ao topo da pilha é direto e não requer deslocamento de elementos.   

Justificativa:  
A Pilha é uma estrutura LIFO (Last In, First Out). Tanto a inserção (push) quanto a remoção (pop) ocorrem apenas no topo. 
Em implementações eficientes (com array ou lista encadeada), o acesso ao topo é direto e leva tempo constante ($O(1)$)1. 
As demais alternativas descrevem complexidades incorretas ou usam o princípio FIFO/LIFO de forma errada.

---

## 5. Questão sobre Operações em Fila (1 PONTO)
Alternativa Correta: (b) A operação dequeue() em uma Fila remove o elemento da frente da fila e tem complexidade $O(1)$ pois o acesso ao primeiro elemento da fila é direto e não requer deslocamento de elementos.   

Justificativa:  
A Fila é uma estrutura FIFO (First In, First Out). A remoção (dequeue) ocorre no início (frente) da fila. 
Em implementações otimizadas (com ponteiros para a frente e o final), a remoção é um acesso direto ao primeiro elemento e leva tempo constante ($O(1)$). 

--- 

## 6. Questão sobre Estruturas de Dados (1 PONTO)
Alternativa Correta: (c) A Lista Encadeada permite inserções e remoções eficientes em qualquer posição (início, meio ou fim), mas não oferece a flexibilidade de acesso aleatório como os arrays.   

Justificativa:  
- (a) e (b) estão incorretas: Pilha é LIFO, Fila é FIFO.
- (c) CORRETA: A lista encadeada permite a modificação de ponteiros para inserção/remoção (eficientes, $O(1)$ no início/fim, $O(N)$ no meio 3), mas não permite acessar um elemento pelo índice $i$ em $O(1)$ como arrays (acesso sequencial, $O(N)$).
- (d) está incorreta: Pilhas podem ser implementadas tanto com arrays quanto com listas.
- (e) está incorreta: Fila segue o princípio FIFO.

---

# Árvores

