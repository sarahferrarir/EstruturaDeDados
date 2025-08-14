#include <iostream>
#include <cstdio>  
using namespace std;

int main()
{
   int a, b, d, e;
   double c, f;

   cin >> a; 
   cin >> b; 
   cin >> c;
   cin >> d; 
   cin >> e;
   cin >> f;

   float valor = b * c + e * f;

    printf("VALOR A PAGAR: R$ %.2lf\n", valor);
    
    return 0;
}