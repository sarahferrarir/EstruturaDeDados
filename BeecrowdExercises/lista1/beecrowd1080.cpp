#include <iostream>
using namespace std;

int main()
{
    int n;
    n = 100;
    int vetor[n]; 
    int x; 
    
    for (int i = 0; i < n; ++i) {
        cin >> x; 
        vetor[i] = x; 
    }
    
    int higher = vetor[0]; 
    int higherposi = 0;
    for (int i = 0; i < n; ++i) {
        if (vetor[i] > higher) {
            higher = vetor[i];
            higherposi = i + 1;
        }
    }
    
    cout << higher << endl;
    cout << higherposi << endl;

    return 0;
    
}
