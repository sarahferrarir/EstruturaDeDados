#include <iostream> 
#include <cstdio>  
using namespace std;

int main() {
    int NUMBER, HOURS;
    float AMOUNT;            

    cin >> NUMBER;
    cin >> HOURS;
    cin >> AMOUNT;

    float SALARY = HOURS * AMOUNT;


    printf("NUMBER = %d\n", NUMBER);
    printf("SALARY = U$ %.2lf\n", SALARY);

    return 0; 
}