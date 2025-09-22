// Title: Ponto do Meio

#include <iostream>
using namespace std; 

int main() {
    long long N;
    cin >> N;
    
    long long side = (1LL << N) + 1; 
    
    cout << side * side << std::endl;
    
    return 0;
}
