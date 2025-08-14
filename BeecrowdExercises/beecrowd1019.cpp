using namespace std;
#include <iostream>

int main()
{
    int N;
    cin >> N;

    int HOURS = N / 3600;
    N = N % 3600;

    int MINUTES = N / 60;
    N = N % 60;

    int SECONDS = N / 1;
    N = N % 1;
    
    cout << HOURS << ":"<< MINUTES << ":" << SECONDS << endl;
    
    return 0;
}