// Title: Domino

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int quant_de_pecas = ((N+1)*(N+2))/2;
    
    cout << quant_de_pecas << endl;

    return 0;
}
