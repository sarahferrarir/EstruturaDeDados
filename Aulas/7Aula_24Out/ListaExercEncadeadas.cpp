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

// -----------------------------------------------------
// EXERCÍCIOS INTERMEDIÁRIOS
// -----------------------------------------------------

// 1. Remover Duplicatas:
// Implemente um método que remova todos os elementos duplicados da lista.
void ListaEncadeada::removerDuplicatas() {
    // Ponteiro externo para percorrer cada nó da lista
    No* atual = Head->prox; 
    
    while (atual != nullptr) {
        // Ponteiro interno para percorrer o restante da lista a partir do nó atual
        No* corredor = atual; 
        
        // Percorre os nós subsequentes ao 'atual'
        while (corredor->prox != nullptr) {
            // Se o dado do nó seguinte for igual ao dado do nó 'atual'
            if (corredor->prox->dado == atual->dado) {
                // Remove o nó duplicado (o nó seguinte)
                No* duplicado = corredor->prox;
                corredor->prox = duplicado->prox; // Pula o nó duplicado
                delete duplicado; // Libera a memória
            } else {
                // Se não for duplicata, avança o corredor
                corredor = corredor->prox;
            }
        }
        // Avança para o próximo nó para checar duplicatas dele
        atual = atual->prox;
    }
}

// 2. Mesclar Duas Listas:
// Escreva uma função que recebe duas listas encadeadas e as mescle em uma terceira lista,
// mantendo a ordem.
// Nota: Este método é estático ou implementado externamente, pois lida com três listas.
// Aqui, vamos implementá-lo como um método que recebe a segunda lista (outra) e mescla
// para uma nova lista, retornando a nova lista. Assumimos que as listas A e B estão ordenadas.
ListaEncadeada* ListaEncadeada::mesclarListas(ListaEncadeada* outra) {
    ListaEncadeada* novaLista = new ListaEncadeada();
    No* p1 = this->Head->prox; // Ponteiro para a primeira lista (this)
    No* p2 = outra->Head->prox; // Ponteiro para a segunda lista (outra)
    No* cauda = novaLista->Head; // Ponteiro para a cauda da nova lista (facilita a inserção O(1))
    
    // Enquanto ambas as listas tiverem elementos
    while (p1 != nullptr && p2 != nullptr) {
        No* noParaInserir = nullptr;
        
        if (p1->dado <= p2->dado) {
            noParaInserir = p1;
            p1 = p1->prox;
        } else {
            noParaInserir = p2;
            p2 = p2->prox;
        }
        
        // Cria um novo nó com o dado e o anexa à nova lista
        cauda->prox = new No(noParaInserir->dado);
        cauda = cauda->prox;
    }
    
    // Anexa o restante dos elementos da lista que não acabou
    No* restante = (p1 != nullptr) ? p1 : p2;
    while (restante != nullptr) {
        cauda->prox = new No(restante->dado);
        cauda = cauda->prox;
        restante = restante->prox;
    }
    
    return novaLista; // Retorna a nova lista mesclada
}

// 3. Ordenar a Lista:
// Crie um método que ordene os elementos da lista encadeada usando o método de ordenação
// por seleção (selection sort) ou outro método de sua escolha.
void ListaEncadeada::ordenarLista() {
    // Usaremos Selection Sort, pois é simples de implementar em listas encadeadas.
    
    // O(N^2) no pior caso.
    
    No* i = Head->prox; // Ponteiro externo (nó que será colocado na posição ordenada)
    
    while (i != nullptr) {
        No* j = i->prox; // Ponteiro interno (percorre o restante da lista)
        No* min = i;     // Ponteiro para o nó com o menor valor encontrado até o momento
        
        // Percorre o restante da lista
        while (j != nullptr) {
            if (j->dado < min->dado) {
                min = j; // Atualiza o nó mínimo
            }
            j = j->prox;
        }
        
        // Troca os dados (não os ponteiros) entre o nó 'i' e o nó 'min'
        if (min != i) {
            int temp = i->dado;
            i->dado = min->dado;
            min->dado = temp;
        }
        
        // Avança o ponteiro externo
        i = i->prox;
    }
}

// -----------------------------------------------------
// EXERCÍCIOS AVANÇADOS
// -----------------------------------------------------

// 1. Encontrar o N-ésimo Elemento do Final:
// Implemente um método que encontre o n-ésimo elemento a partir do final da lista.
int ListaEncadeada::encontrarNesimoDoFinal(int n) {
    if (n <= 0 || Head->prox == nullptr) {
        return -1; // Condição de erro
    }

    No* ponteiroLento = Head->prox;
    No* ponteiroRapido = Head->prox;

    // 1. Avança o ponteiro rápido 'n' vezes para criar a distância
    for (int i = 0; i < n; ++i) {
        if (ponteiroRapido == nullptr) {
            // N é maior que o tamanho da lista
            return -1;
        }
        ponteiroRapido = ponteiroRapido->prox;
    }

    // 2. Avança ambos os ponteiros juntos até que o rápido chegue ao fim
    while (ponteiroRapido != nullptr) {
        ponteiroLento = ponteiroLento->prox;
        ponteiroRapido = ponteiroRapido->prox;
    }

    // O ponteiro lento agora está no N-ésimo nó a partir do final
    return ponteiroLento->dado;
}

// 2. Remover N-ésimo Elemento:
// Escreva um método que remova o n-ésimo elemento da lista encadeada (a partir do início).
void ListaEncadeada::removerNesimoElemento(int n) {
    // Assume que a função contarElementos() está implementada e que n > 0.
    if (n <= 0 || Head->prox == nullptr || n > contarElementos()) {
        return;
    }

    // O nó 'p' deve parar no nó ANTERIOR ao que será removido.
    // O nó anterior ao n-ésimo está na posição n-1 (contando a partir da cabeça,
    // que seria a posição 0).
    No* p = Head; 
    for (int i = 0; i < n - 1; ++i) {
        p = p->prox;
    }
    
    // Remove o nó:
    No* remover = p->prox;
    p->prox = remover->prox;
    delete remover;
}

// 3. Duplicar a Lista:
// Crie uma função que duplique cada elemento da lista.
void ListaEncadeada::duplicarLista() {
    No* p = Head->prox;
    
    while (p != nullptr) {
        // 1. Cria um novo nó com o mesmo dado
        No* duplicado = new No(p->dado);
        
        // 2. Insere o nó duplicado após o nó atual (p)
        duplicado->prox = p->prox; // O duplicado aponta para o próximo do original
        p->prox = duplicado;       // O original aponta para o duplicado
        
        // 3. Avança o ponteiro 'p' duas posições para o próximo nó original
        p = duplicado->prox;
    }
}

// 4. Reverter a Lista Recursivamente:
// Implementa um método que inverte a lista encadeada usando recursão.

// Função auxiliar recursiva que faz o trabalho de inversão
No* reverterRecursivo(No* atual, No* anterior) {
    // Caso base: Se a lista acabar, retorna o último nó (que será o novo Head->prox)
    if (atual == nullptr) {
        return anterior;
    }
    
    // 1. Salva o próximo nó
    No* proximo = atual->prox;
    
    // 2. Inverte o ponteiro do nó atual
    atual->prox = anterior;
    
    // 3. Chama a função recursivamente para o restante da lista
    return reverterRecursivo(proximo, atual);
}

// Método público da classe ListaEncadeada
void ListaEncadeada::reverterListaRecursivamente() {
    // Inicia a recursão e armazena o novo primeiro nó (a antiga cauda) em Head->prox
    Head->prox = reverterRecursivo(Head->prox, nullptr);
}
