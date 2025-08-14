#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    
    int HOURS, SPEED;
    cin >> HOURS >> SPEED;

    double DISTANCE = HOURS * SPEED;

    double TOTAL = DISTANCE/12;
    
    printf("%.3lf\n", TOTAL)

    return 0;
}