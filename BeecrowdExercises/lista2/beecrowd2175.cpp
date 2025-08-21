//Title: What Is The Fastest?

#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    float O, B, I;
    cin >> O >> B >> I;
    
   
    cout << fixed << setprecision(3);

    if (O < B && O < I)
        cout << "Otavio" << endl;
    else if (B < I && B < O)
        cout << "Bruno" << endl;
    else if (I < O && I < B)
        cout << "Ian" << endl;
    else
        cout << "Empate" << endl;

    return 0;
}
