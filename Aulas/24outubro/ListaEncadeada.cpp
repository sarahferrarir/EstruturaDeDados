// -------------------------------------------
// LISTA ENCADEADA SIMPLES
// Nesta lista, cada nó aponta para o próximo.
// O último nó aponta para NULL.
// Há um nó cabeça (sentinela) para facilitar
// as operações de inserção e remoção.
// -------------------------------------------

#include <iostream>
using namespace std;

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

    // Métodos básicos
    void addInicio(int x);
    void addFim(int x);
    void busca(int x);
    void remove(int x);
    void imprime();
};

// Insere um elemento no início da lista
void ListaEncadeada::addInicio(int x) {
    No* novo = new No(x);
    novo->prox = Head->prox; // o novo nó aponta para o antigo primeiro
    Head->prox = novo;       // a cabeça aponta para o novo nó
}

// Insere um elemento no final da lista
void ListaEncadeada::addFim(int x) {
    No* p = Head;
    while (p->prox != nullptr)
        p = p->prox;
    p->prox = new No(x);
}

// Busca um elemento na lista
void ListaEncadeada::busca(int x) {
    No* p = Head->prox;
    while (p != nullptr) {
        if (p->dado == x) {
            cout << "Elemento " << x << " encontrado!" << endl;
            return;
        }
        p = p->prox;
    }
    cout << "Elemento " << x << " nao encontrado!" << endl;
}

// Remove um elemento da lista
void ListaEncadeada::remove(int x) {
    No* p = Head;
    while (p->prox != nullptr && p->prox->dado != x)
        p = p->prox;

    if (p->prox != nullptr) {
        No* remover = p->prox;
        p->prox = remover->prox;
        delete remover;
        cout << "Elemento " << x << " removido!" << endl;
    } else {
        cout << "Elemento " << x << " nao encontrado!" << endl;
    }
}

// Imprime todos os elementos da lista
void ListaEncadeada::imprime() {
    No* p = Head->prox;
    cout << "Lista: ";
    while (p != nullptr) {
        cout << p->dado << " ";
        p = p->prox;
    }
    cout << endl;
}

// ------------------------------
// Programa principal de teste
// ------------------------------
int main() {
    ListaEncadeada lista;

    lista.addInicio(10);
    lista.addInicio(5);
    lista.addFim(20);
    lista.imprime();

    lista.busca(10);
    lista.remove(5);
    lista.imprime();

    lista.busca(99);

    return 0;
}
