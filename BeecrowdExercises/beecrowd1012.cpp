#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    double A, B, C;
    cin >> A >> B >> C;
    
    double pi = 3.14159;

    double TRIANGLE = (A * C) / 2.0;
    double CIRCLE = pi * pow(C, 2);
    double TRAPEZIUM = ((A + B) * C) / 2.0;
    double SQUARE = pow(B, 2);
    double RECTANGLE = A * B;

    printf("TRIANGULO:  %.3lf\n", TRIANGLE);
    printf("CIRCULO: %.3lf\n", CIRCLE);
    printf("TRAPEZIO: %.3lf\n", TRAPEZIUM);
    printf("QUADRADO: %.3lf\n", SQUARE);
    printf("RETANGULO: %.3lf\n", RECTANGLE);

    return 0;
}
