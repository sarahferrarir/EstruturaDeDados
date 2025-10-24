// -------------------------------------------
// LISTA CIRCULAR DUPLAMENTE ENCADEADA
// Nesta lista, o último nó aponta para o primeiro,
// e o primeiro aponta para o último.
// O nó cabeça (Head) aponta para si mesmo
// quando a lista está vazia.
// -------------------------------------------

#include <iostream>
using namespace std;

// Nó da lista circular duplamente encadeada
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

// Classe da lista circular duplamente encadeada
class ListaEncadeada {
public:
    No* Head;

    ListaEncadeada() {
        this->Head = new No();   // cria nó cabeça
        Head->prox = Head;       // aponta para si mesmo (lista vazia)
        Head->ant = Head;
    }

    void addInicio(int x);
    void addFim(int x);
    void busca(int x);
    void remove(int x);
    void imprime();
};

// Insere no início da lista
void ListaEncadeada::addInicio(int x) {
    No* novo = new No(x);
    novo->prox = Head->prox;
    novo->ant = Head;
    Head->prox->ant = novo;
    Head->prox = novo;
}

// Insere no final da lista
void ListaEncadeada::addFim(int x) {
    No* novo = new No(x);
    novo->ant = Head->ant;
    novo->prox = Head;
    Head->ant->prox = novo;
    Head->ant = novo;
}

// Busca um elemento
void ListaEncadeada::busca(int x) {
    No* p = Head->prox;
    while (p != Head) {
        if (p->dado == x) {
            cout << "Elemento " << x << " encontrado!" << endl;
            return;
        }
        p = p->prox;
    }
    cout << "Elemento " << x << " nao encontrado!" << endl;
}

// Remove um elemento
void ListaEncadeada::remove(int x) {
    No* p = Head->prox;
    while (p != Head && p->dado != x)
        p = p->prox;

    if (p != Head) {
        p->ant->prox = p->prox;
        p->prox->ant = p->ant;
        delete p;
        cout << "Elemento " << x << " removido!" << endl;
    } else {
        cout << "Elemento " << x << " nao encontrado!" << endl;
    }
}

// Imprime os elementos da lista
void ListaEncadeada::imprime() {
    No* p = Head->prox;
    cout << "Lista: ";
    while (p != Head) {
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
    lista.addFim(20);
    lista.addFim(30);
    lista.imprime();

    lista.busca(20);
    lista.remove(10);
    lista.imprime();

    lista.busca(99);

    return 0;
}
