// Tarefa: Desenvolva uma função Fibonacci recursiva
// LINK para o drive: 
https://drive.google.com/drive/folders/1821z9Z591PiBzrSac0tf4QXBQjdgpT7x?usp=sharing
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
#include <iostream>
using namespace std;

long long int fibo(int x){
    if(x == 0)
        return 0;
    if(x == 1)
        return 1;
    return fibo(x - 1) + fibo(x -2);
}

int main(){
    int n;
    cin >> n;
    cout << fibo(n) << endl;

    return 0;
}
