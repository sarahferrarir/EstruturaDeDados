using namespace std;
#include <iostream>
#include <cstdio>  

int main() {
    double taxes = 0.0;
    double salary;
    cin >> salary;

    if (salary <= 2000.00) {
        printf("Isento\n");
        
    } else {
        if (salary > 4500.00) {
            taxes = taxes + (salary - 4500.00) * 0.28;
            salary = 4500.00;
        }
        if (salary > 3000.00) {
            taxes = taxes + (salary - 3000.00) * 0.18;
            salary = 3000.00;
        }
        if (salary > 2000.00) {
            taxes = taxes + (salary - 2000.00) * 0.08;
        }

        printf("R$ %.2lf\n", taxes);
    }

    return 0;
}
