// Title: World Cup

#include <iostream>
#include <string>
using namespace std;

int main() {
    int T, N;
    while (cin >> T >> N) {
        if (T == 0 && N == 0) break;

        int soma = 0;
        string pais;
        int pontos;
        for (int i = 0; i < T; i++) {
            cin >> pais >> pontos; 
            soma += pontos;
        }

        int empates = 3 * N - soma; 
        cout << empates << endl;
    }
    return 0;
}
