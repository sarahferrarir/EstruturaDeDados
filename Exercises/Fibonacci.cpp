// Tarefa: Desenvolva uma função Fibonacci recursiva

// Minha resposta
#include <iostream>
using namespace std;

int fibo(int n) {
    if (n <= 1) {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    int n;
    cout << "Posição n: ";
    cin >> n;

    cout << "Fibonacci de " << n << " é " << fibo(n) << endl;

    return 0;
}


// Gabarito do Professor 
/* implementação de Fibonacci com memoização (armazenamento de resultados já calculados)

Resumo das vantagens desse jeito:
Velocidade — elimina cálculos repetidos.
Eficiência — reaproveita resultados já calculados.
Segurança — reduz risco de estouro de pilha.
Versatilidade — fácil de adaptar para outros problemas.
Escalabilidade — funciona para valores muito grandes de n.
*/

#include <iostream>
using namespace std;

long long fibonacci[100001];

long long int fibo(int x){
    if(fibonacci[x] != -1){
        return fibonacci[x]; 
    }
    if(x == 0){
        fibonacci[x] = x;
        return 0;
    }
    if(x == 1){
        fibonacci[x] = x;
        return 1;
    }
    fibonacci[x] = fibo(x - 1) + fibo(x -2);
}

void inicializarvetor(){
    for (int i = 0; i < 100001; i++){
        fibonacci[i] = -1;
    }
}

int main(){
    inicializarvetor();
    int m;
    cout << "Quantas operações deseja realizar?" << endl;
    cin >> m;
    
    while (m--){
        cout << "Valor do fibonacci: ";
        int n;
        cin >> n;
        cout << fibo(n) << endl;
    }

    return 0;
}  

/* 
1. Economia de tempo (desempenho muito melhor)
No Fibonacci recursivo comum:
fibo(n) = fibo(n-1) + fibo(n-2)
O mesmo valor é recalculado várias e várias vezes.
Para fibo(50), por exemplo, o número de chamadas recursivas explode para milhões.
 - Com memoização (fibonacci[x] != -1), cada valor é calculado apenas uma vez e depois é recuperado instantaneamente da memória.

2. Armazenamento para múltiplas consultas
Você inicializa o vetor fibonacci[] com -1 para indicar valores ainda não calculados.
Depois, se o usuário pedir fibo(40) e depois fibo(42), o programa não recalcula todo o caminho — ele usa os valores já armazenados (fibo(40) e fibo(41)) para chegar ao resultado.
*/
