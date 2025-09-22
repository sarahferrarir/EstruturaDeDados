// Title: Keanu

using namespace std;
#include <iostream>

int main()
{
   int n;
   cin >> n;
   
  int a, b;
    if (n % 2 == 0) {
        a = b = (n * n) / 2;
    } else {
        a = (n * n + 1) / 2;
        b  = (n * n - 1) / 2;
    }

    cout << a << " casas brancas e " << b << " casas pretas" << endl;
    return 0;
}