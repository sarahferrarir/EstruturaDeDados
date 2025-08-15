#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double X1, Y1, X2, Y2;
    cin >> X1;
    cin >> Y1;
    cin >> X2;
    cin >> Y2;

    double DISTANCIA = sqrt(pow(X2 - X1, 2) + pow(Y2 - Y1, 2));

    cout << fixed << setprecision(4)<< DISTANCIA << endl;
    
    return 0;
}
