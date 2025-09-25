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

// Função merge recebe o vetor como referência
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    // Combina os dois subvetores ordenadamente
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    // Copia o restante de cada subvetor
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    // Copia de volta para o vetor original
    for (int k = left; k <= right; ++k)
        arr[k] = temp[k - left];
}

// Função recursiva mergeSort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return; // caso base
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);       // ordena metade esquerda
    mergeSort(arr, mid + 1, right);  // ordena metade direita
    merge(arr, left, mid, right);    // combina as duas metades
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};

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

// Função partition recebe o vetor como referência
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Função recursiva quickSort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // partição
        quickSort(arr, low, pi - 1);        // esquerda
        quickSort(arr, pi + 1, high);       // direita
    }
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};

    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
```
