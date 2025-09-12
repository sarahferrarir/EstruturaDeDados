#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    for (int i = 0; i < 4; i++) {
        int menor = i;
        
        for (int j = i + 1; j < 5; j++){
            if (arr[j] < arr[menor]){
                menor = j;
            }
        }
        
        if (menor != i) {
        // swap(arr[i], arr[menor]);
        // Sem a função swap: 
            int k = arr[i];
            arr[i] = arr[menor];
            arr[menor] = k;
        }
    }
}

int main() {
    vector<int> num = {5, 3, 8, 4, 2};

    selectionSort(num);

    cout << "Array ordenado:  ";
    for (int n : num) cout << n << " ";
    cout << endl;

    return 0;
}
