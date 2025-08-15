using namespace std;
#include <iostream>

int main()
{
    int DAY;
    cin >> DAY;

    int YEARS = DAY / 365;  
    DAY = DAY % 365; 

    int MONTHS = DAY / 30;  
    DAY = DAY % 30;  

    cout << YEARS << " ano(s)" << endl;
    cout << MONTHS << " mes(es)" << endl;
    cout << DAY << " dia(s)" << endl;
    
    return 0;
}
