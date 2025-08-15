#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int X;
    cin >> X;

    double Y;
    cin >> Y;

    double CONSUMPTION = X / Y;

    printf("%.3lf km/l\n", CONSUMPTION);

    return 0;
}
