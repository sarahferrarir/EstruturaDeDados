#include <iostream>

// -----------------------------------------------------
// Estrutura de Dados - Lista 3 : Listas Encadeadas
// -----------------------------------------------------

// Classe que representa um nó da lista
class No {
public:
    int dado;
    No* prox;

    // Construtor: inicializa o valor e o ponteiro
    No(int valor = 0) {
        dado = valor;
        prox = nullptr;
    }
};

// Classe que representa a lista encadeada simples
class ListaEncadeada {
public:
    No* Head; // nó cabeça (não armazena dado útil)

    ListaEncadeada() {
        this->Head = new No(); // cria o nó cabeça
    }
};

// -----------------------------------------------------
// EXERCÍCIOS BÁSICOS
// -----------------------------------------------------

// 1. Contar Elementos:
// Implemente um método na classe ListaEncadeada que conte e retorne o número de elementos na lista.
int ListaEncadeada::contarElementos() {
    int contador = 0;
    // Começa do primeiro nó útil (após a cabeça)
    No* p = Head->prox; 
    
    while (p != nullptr) {
        contador++;
        p = p->prox;
    }
    return contador;
}

// 2. Buscar Elemento:
// Crie um método que busque um elemento na lista e retorne true se ele existir ou false caso contrário.
bool ListaEncadeada::buscarElemento(int x) {
    // Começa do primeiro nó útil (após a cabeça)
    No* p = Head->prox; 
    
    while (p != nullptr) {
        if (p->dado == x) {
            return true; // Elemento encontrado
        }
        p = p->prox; // Avança para o próximo nó
    }
    return false; // Elemento não encontrado
}

// 3. Inverter a Lista:
// Escreva uma função que inverta a ordem dos elementos na lista encadeada.
void ListaEncadeada::inverterLista() {
    // Três ponteiros auxiliares para a inversão
    No* anterior = nullptr;
    No* atual = Head->prox; // Começa do primeiro nó útil
    No* proximo = nullptr;

    // 1. Inverte os ponteiros 'prox' de cada nó
    while (atual != nullptr) {
        proximo = atual->prox;  // Salva o próximo nó original
        atual->prox = anterior; // Inverte o ponteiro (aponta para o anterior)
        anterior = atual;       // Move 'anterior' para o nó atual
        atual = proximo;        // Move 'atual' para o próximo nó original
    }
    
    // 2. O nó cabeça deve apontar para o novo primeiro elemento (o 'anterior' final)
    Head->prox = anterior;
}

// 4. Adicionar ao Fim:
// Modifique a classe para adicionar um novo método que insira um elemento no final da lista.
void ListaEncadeada::adicionarAoFim(int x) {
    // Ponteiro para percorrer a lista
    No* p = Head; 
    
    // Percorre a lista até encontrar o último nó (aquele cujo 'prox' é nullptr)
    while (p->prox != nullptr) {
        p = p->prox;
    }
    
    // 'p' agora é o último nó. Cria-se o novo nó e o anexa a 'p'.
    No* nova = new No(x);
    p->prox = nova;
}
