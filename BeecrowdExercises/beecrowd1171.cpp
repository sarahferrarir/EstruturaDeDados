#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> numbers(N);
    
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    int count = 1;
    
    for (int i = 1; i < N; i++) {
        if (numbers[i] == numbers[i - 1]) {
            count++;
        } else {
            cout << numbers[i - 1] << " aparece " << count << " vez(es)" << endl;
            count = 1;  
        }
    }
    cout << numbers[N - 1] << " aparece " << count << " vez(es)" << endl;

    return 0;
}
