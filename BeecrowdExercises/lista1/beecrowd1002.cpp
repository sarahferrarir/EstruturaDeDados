#include <iostream> 
#include <cstdio>  
using namespace std;

int main() {
    double R;         
    double pi = 3.14159;
    double A;         

    cin >> R;

    A = pi * R * R;

    printf("A=%.4lf\n", A);

    return 0; 
}
