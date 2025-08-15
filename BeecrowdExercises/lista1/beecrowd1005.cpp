#include <iostream> 
#include <cstdio>  
using namespace std;

int main() {
    double A, B;                  

    cin >> A;
    cin >> B;

    float MEDIA = (A * 3.5 + B * 7.5) / (3.5 + 7.5);

    printf("MEDIA = %.5lf\n", MEDIA);

    return 0; 
}
