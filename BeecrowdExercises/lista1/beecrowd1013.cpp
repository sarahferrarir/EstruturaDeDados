#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){

    int A, B, C;
    cin >> A >> B >> C;

    int MAIORAB = (A + B + abs(A - B)) / 2;
    int MAIOR = (MAIORAB + C + abs(MAIORAB-C)) /2;

    printf("%d eh o maior\n", MAIOR);
  
    return 0;
}
