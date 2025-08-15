#include <iostream>
#include <cstdio>  
#include <cmath>
using namespace std;

int main()
{
    double R, pi;

    cin >> R;
    pi = 3.14159;

    double volume = (4.0/3) * pi * pow(R, 3);

    printf("VOLUME = %.3lf\n", volume);

    return 0;
}
