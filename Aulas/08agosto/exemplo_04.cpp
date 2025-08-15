#include <iostream> // Libs Entrada/Saída C++
#include <cstdio>  // // Libs Entrada/Saída C
#include <iomanip>
using namespace std;

// Tipo nome (conjunto de parametros){} Assinatura da função
int main(){
    float x = 64.64543242;
    double y = 64.64543242;

    printf("%.2f\n",x);
    printf("%.2f\n",y);
    cout << fixed << setprecision(4) << x << endl;
    return 0;

}

