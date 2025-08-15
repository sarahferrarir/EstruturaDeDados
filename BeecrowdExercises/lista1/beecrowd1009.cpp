#include <iostream> 
#include <cstdio>  
using namespace std;

int main() {
    string NAME;
    double SALARY, SALE;   

    cin >> NAME;
    cin >> SALARY;
    cin >> SALE;

    double TOTAL = SALARY + (SALE * 0.15);

    printf("TOTAL = R$ %.2lf\n", TOTAL);

    return 0; 
}
