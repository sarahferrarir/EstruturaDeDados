// -------------------------------------------
// LISTA DUPLAMENTE ENCADEADA
// Cada nó possui dois ponteiros:
// um para o próximo (prox)
// e outro para o anterior (ant).
// O nó cabeça facilita as operações.
// -------------------------------------------

#include <iostream>
using namespace std;

// Nó da lista duplamente encadeada
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

// Classe da lista duplamente encadeada
class ListaDupla {
public:
    NoDuplo* Head;

    ListaDupla() {
        this->Head = new NoDuplo(); // nó cabeça
    }

    void addInicio(int x);
    void addFim(int x);
    void busca(int x);
    void remove(int x);
    void imprime();
};

// Insere no início
void ListaDupla::addInicio(int x) {
    NoDuplo* novo = new NoDuplo(x);
    novo->prox = Head->prox;
    novo->ant = Head;
    if (Head->prox != nullptr)
        Head->prox->ant = novo;
    Head->prox = novo;
}

// Insere no fim
void ListaDupla::addFim(int x) {
    NoDuplo* p = Head;
    while (p->prox != nullptr)
        p = p->prox;
    NoDuplo* novo = new NoDuplo(x);
    p->prox = novo;
    novo->ant = p;
}

// Busca
void ListaDupla::busca(int x) {
    NoDuplo* p = Head->prox;
    while (p != nullptr) {
        if (p->dado == x) {
            cout << "Elemento " << x << " encontrado!" << endl;
            return;
        }
        p = p->prox;
    }
    cout << "Elemento " << x << " nao encontrado!" << endl;
}

// Remove
void ListaDupla::remove(int x) {
    NoDuplo* p = Head->prox;
    while (p != nullptr && p->dado != x)
        p = p->prox;

    if (p != nullptr) {
        if (p->prox != nullptr)
            p->prox->ant = p->ant;
        p->ant->prox = p->prox;
        delete p;
        cout << "Elemento " << x << " removido!" << endl;
    } else {
        cout << "Elemento " << x << " nao encontrado!" << endl;
    }
}

// Imprime
void ListaDupla::imprime() {
    NoDuplo* p = Head->prox;
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
    ListaDupla lista;

    lista.addInicio(10);
    lista.addInicio(5);
    lista.addFim(20);
    lista.imprime();

    lista.remove(10);
    lista.imprime();

    lista.busca(20);
    lista.busca(99);

    return 0;
}
