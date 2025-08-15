#include <iostream>
#include <cstdio> // include <stdio.h>
#include <iomanip> // fixed, setprecision
#include <cmath> // pow(valor, expoente), sqrt
using namespace std;

int main(){

    double x = 3.1415163056342;
    cout << x << endl;
    printf("A=%.4f\n",x);
    cout << fixed << setprecision(4) << "Valor =" << x << endl;

    return 0;
}