# Comparativo entre os algoritmos

| Algoritmo   | Complexidade        | Estável | Observações                          |
|------------ |------------------  |-------- |-------------------------------------|
| Quick Sort  | O(n log n) média    | Não     | Mais rápido na prática               |
| Merge Sort  | O(n log n) garantido| Sim     | Usa mais memória                     |
| Heap Sort   | O(n log n) garantido| Não     | Muitas trocas, cache ruim            |

## Conclusão

- **Quick Sort** é eficiente e geralmente preferido, exceto quando a estabilidade é necessária.  
- **Merge Sort** é estável e previsível, ideal para dados grandes e ordenação externa.  
- **Heap Sort** é usado quando memória é restrita e precisa de complexidade garantida.
---

## 1. Counting Sort
```cpp
#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0), output(arr.size());

    // Contagem
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - minVal]++;
    }

    // Acumulando
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Construir saída
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[--count[arr[i] - minVal]] = arr[i];
    }

    arr = output;
}

int main() {
    vector<int> arr = {9, 3, 4, 1, 7, 6};
    countingSort(arr);

    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
```

## 2. Merge Sort

```cpp
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    vector<int> arr = {9, 3, 4, 1, 7, 6};
    mergeSort(arr, 0, arr.size() - 1);

    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
```

## 3. Quick Sort
```cpp
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {9, 3, 4, 1, 7, 6};
    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
```
