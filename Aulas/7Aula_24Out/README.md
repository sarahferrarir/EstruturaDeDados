# Listas Encadeadas  

## 📘 Introdução Geral: Ponteiros, Memória e Estruturas Dinâmicas

Antes de entender listas encadeadas, é essencial compreender o **conceito de ponteiros** e **alocação dinâmica de memória**, pois essas estruturas dependem totalmente deles.

### 🔹 O que são Ponteiros

Um **ponteiro** é uma variável que **guarda o endereço de memória** de outra variável.  
Se uma variável comum guarda um valor (como `int x = 10`), um ponteiro guarda o *endereço onde esse valor está salvo*.

```cpp
int x = 10;
int* p = &x; // p armazena o endereço de x
```
- `&x` → operador “endereço de”  
- `*p` → operador “conteúdo apontado por”

Assim:

- `p` guarda o endereço de `x`;  
- `*p` acessa o valor de `x` (nesse caso, 10).

### 🔹 Ponteiros e Alocação Dinâmica
Na linguagem C/C++, é possível reservar memória durante a execução do programa (em tempo de execução) usando o operador `new`.

```cpp
int* p = new int; // aloca um inteiro na memória heap
*p = 42;          // atribui valor
delete p;         // libera a memória (evita vazamentos)
```
Essa capacidade é essencial para estruturas de dados dinâmicas, como **listas encadeadas, pilhas, filas e árvores**, que precisam crescer e diminuir conforme o programa roda — diferente de um vetor, que tem tamanho fixo.

--- 
## 📗 Motivação: Por que usar Listas Encadeadas?
Os **vetores** (arrays) têm duas grandes limitações:

1. São armazenados contiguamente na memória.
2. Têm tamanho fixo definido na alocação.

Isso causa problemas:  
- Pode haver memória livre suficiente, mas não de forma contígua.
- Pode sobrar espaço (vetor muito grande) ou faltar (vetor pequeno demais).

> 👉 Listas encadeadas resolvem isso com alocação sob demanda: cada novo elemento é criado dinamicamente e “ligado” ao anterior por meio de ponteiros.

---
## 📘 Estrutura Base: Nó (ou Célula)
Em todas as listas, temos uma unidade fundamental: o ***nó***.

```cpp
class No {
public:
    int dado;   // valor armazenado
    No* prox;   // ponteiro para o próximo nó
};
```
Um ***nó*** guarda:  
- Um **dado** (por exemplo, um número inteiro);
- Um **ponteiro** para o **próximo nó** (ou também para o anterior, no caso de listas duplas).

---
## 📗 Tipos de Listas Encadeadas
As três principais variações são:

| Tipo                       | Direção                | Último nó aponta para | Ponteiros por nó  | Complexidade de Inserção       |
|-----------------------------|------------------------|------------------------|------------------|--------------------------------|
| **Simples**                 | Única (próximo)        | `NULL`                 | 1 (`prox`)       | Início: **O(1)**, Fim: **O(n)** |
| **Duplamente Encadeada**    | Duas direções          | `NULL`                 | 2 (`ant`, `prox`) | Início/Fim: **O(1)**            |
| **Circular Duplamente Encadeada** | Duas direções (circular) | Primeiro nó           | 2 (`ant`, `prox`) | Início/Fim: **O(1)**            |

---
## 🧩 1️⃣ Lista Encadeada Simples
### 🔹 Conceito
A lista encadeada simples é uma coleção de nós em sequência, onde cada nó aponta apenas para o próximo.   
O último nó aponta para `NULL`, indicando o final da lista.

### 🔹 Estrutura de um Nó
```cpp
class No {
public:
    int dado;
    No* prox;
    No(int valor = 0) {
        dado = valor;
        prox = nullptr;
    }
};
```

### 🔹 Estrutura da Lista
A lista possui um nó cabeça (Head) que não armazena dado útil, servindo como ponto fixo de acesso.

```cpp
class ListaEncadeada {
public:
    No* Head;
    ListaEncadeada() {
        this->Head = new No(); // nó cabeça
    }
};
```

### 🔹 Operações Principais
➤ **Inserção no início (O(1))**

```cpp
void addInicio(int x) {
    No* novo = new No(x);
    novo->prox = Head->prox;
    Head->prox = novo;
}
```
O novo nó aponta para o antigo primeiro, e a cabeça passa a apontar para o novo.

➤ **Inserção no fim (O(n))**
Percorre até o final e adiciona o novo nó após o último.

```cpp
void addFim(int x) {
    No* p = Head;
    while (p->prox != nullptr)
        p = p->prox;
    p->prox = new No(x);
}
```

➤ **Busca (O(n))**
Percorre a lista até encontrar o valor ou chegar ao fim.

➤ **Remoção (O(n))**
Ajusta os ponteiros para “pular” o nó removido e liberar sua memória.

```cpp
void remove(int x) {
    No* p = Head;
    while (p->prox != nullptr && p->prox->dado != x)
        p = p->prox;

    if (p->prox != nullptr) {
        No* remover = p->prox;
        p->prox = remover->prox;
        delete remover;
    }
}
```

---
## 2️⃣ Lista Duplamente Encadeada
### 🔹 Conceito
Cada nó guarda dois ponteiros:  
- `prox` → para o próximo nó;  
- `ant` → para o nó anterior.  

Isso permite percorrer a lista em ambas as direções.

### 🔹 Estrutura do Nó

```cpp
class NoDuplo {
public:
    int dado;
    NoDuplo* prox;
    NoDuplo* ant;
    NoDuplo(int valor = 0) {
        dado = valor;
        prox = nullptr;
        ant = nullptr;
    }
};
```

### 🔹 Estrutura da Lista
Usa também um nó cabeça (Head).   
O primeiro elemento tem `ant = Head` e o último tem `prox = nullptr`.

### 🔹 Operações
➤ Inserção no início

```cpp
void addInicio(int x) {
    NoDuplo* novo = new NoDuplo(x);
    novo->prox = Head->prox;
    novo->ant = Head;
    if (Head->prox != nullptr)
        Head->prox->ant = novo;
    Head->prox = novo;
}
```

➤ Inserção no fim

```cpp
void addFim(int x) {
    NoDuplo* p = Head;
    while (p->prox != nullptr)
        p = p->prox;
    NoDuplo* novo = new NoDuplo(x);
    p->prox = novo;
    novo->ant = p;
}
```

➤ Remoção
Ajusta ambos os ponteiros (`ant` e `prox`) ao retirar o nó:

```cpp
if (p->prox != nullptr)
    p->prox->ant = p->ant;
p->ant->prox = p->prox;
delete p;
```

### 🔹 Vantagens
- Navegação em dois sentidos;
- Remoção mais simples (não precisa percorrer procurando o nó anterior);
- Flexibilidade em manipulação.

## 3️⃣ Lista Circular Duplamente Encadeada
### 🔹 Conceito
É uma lista onde o último elemento aponta para o primeiro e o primeiro aponta para o último, formando um ciclo fechado.  
Além disso, existe um nó cabeça que aponta para si mesmo quando a lista está vazia.

```cpp
Head->prox = Head;
Head->ant = Head;
```

### 🔹 Estrutura do Nó

```cpp
class No {
public:
    int dado;
    No* prox;
    No* ant;
    No(int valor = 0) {
        dado = valor;
        prox = nullptr;
        ant = nullptr;
    }
};
```

### 🔹 Operações
➤ Inserção no início (O(1))

```cpp
void addInicio(int x) {
    No* novo = new No(x);
    novo->prox = Head->prox;
    novo->ant = Head;
    Head->prox->ant = novo;
    Head->prox = novo;
}
```

➤ Inserção no fim (O(1))

```cpp
void addFim(int x) {
    No* novo = new No(x);
    novo->ant = Head->ant;
    novo->prox = Head;
    Head->ant->prox = novo;
    Head->ant = novo;
}
```

➤ Busca
Percorre do primeiro ao último, verificando se p != Head.

➤ Remoção

```cpp
void remove(int x) {
    No* p = Head->prox;
    while (p != Head && p->dado != x)
        p = p->prox;

    if (p != Head) {
        p->ant->prox = p->prox;
        p->prox->ant = p->ant;
        delete p;
    }
}
```

---
### 🔹 Características

| Operação         | Complexidade | Observação                     |
|------------------|--------------|--------------------------------|
| Inserção início  | **O(1)**     | direta                         |
| Inserção fim     | **O(1)**     | sem percorrer lista             |
| Busca            | **O(n)**     | percorre até voltar ao `Head`   |
| Remoção          | **O(n)**     | segura, sem ponteiro nulo       |

---

### 🧾 Comparativo Geral

| Tipo                | Ponteiros          | Direção | Circular | Custo addInicio | Custo addFim | Custo busca/remover |
|---------------------|--------------------|----------|-----------|------------------|---------------|----------------------|
| **Simples**         | 1 (`prox`)         | →        | Não       | **O(1)**         | **O(n)**      | **O(n)**             |
| **Dupla**           | 2 (`prox`, `ant`)  | ↔        | Não       | **O(1)**         | **O(n)**      | **O(n)**             |
| **Circular Dupla**  | 2 (`prox`, `ant`)  | ↔        | Sim       | **O(1)**         | **O(1)**      | **O(n)**             |

---

### 🧮 Complexidade e Uso Prático

| Operação            | Lista Simples | Lista Dupla | Lista Circular Dupla |
|---------------------|----------------|--------------|-----------------------|
| Inserção no início  | **O(1)**       | **O(1)**     | **O(1)**              |
| Inserção no fim     | **O(n)**       | **O(n)**     | **O(1)**              |
| Remoção por valor   | **O(n)**       | **O(n)**     | **O(n)**              |
| Busca               | **O(n)**       | **O(n)**     | **O(n)**              |

---

### 💡 Aplicações Reais

| Tipo                | Exemplos de uso |
|---------------------|-----------------|
| **Simples**         | Implementação de filas, listas básicas |
| **Dupla**           | Sistemas de “desfazer/refazer”, players de música |
| **Circular Dupla**  | Algoritmos de rotação (ex: escalonamento de processos, jogos de turno) |

---
## ⚙️ Cuidados e Boas Práticas
1. **Destrutor (`~Lista`)**  
Sempre libere a memória dos nós para evitar *memory leaks*.

```cpp
~ListaEncadeada() {
    while (Head->prox != nullptr)
        remove(Head->prox->dado);
    delete Head;
}
```

2. **Verifique Ponteiros**  
Sempre confirme se `p != nullptr` antes de acessar `p->prox`.  

3. **Evite acessar após `delete`**   
Um ponteiro liberado (dangling pointer) é perigoso — nunca o use após deletar.

4. **Documente e teste**  
Sempre teste casos: lista vazia, 1 elemento, remover início/fim, elemento inexistente.

---

## 🧠 Conclusão
Listas encadeadas são a base de **estruturas dinâmicas** em programação.  
Compreender seu funcionamento é essencial para entender:  
- Pilhas e filas (derivadas de listas);
- Árvores e grafos (estruturas ligadas por ponteiros);
- Alocação dinâmica e gerenciamento de memória.

A principal diferença entre as listas é o nível de encadeamento e circularidade:  
- **Simples**: ligação unidirecional.
- **Dupla**: ligação bidirecional.
- **Circular**: ligação cíclica (sem ponteiros nulos).
