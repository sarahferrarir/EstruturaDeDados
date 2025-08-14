#include <iostream> 
#include <cstdio>  
using namespace std;

int main() {
    double A, B, C;                  

    cin >> A;
    cin >> B;
    cin >> C;

    float MEDIA = (A * 2 + B * 3 + C * 5) / (2 + 3 + 5);

    printf("MEDIA = %.1lf\n", MEDIA);

    return 0; 
}