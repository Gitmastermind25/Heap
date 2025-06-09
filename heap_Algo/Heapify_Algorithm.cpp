#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;

    if (leftIndex <= n && arr[leftIndex] > arr[largest]) {
        largest = leftIndex;
    }
    if (rightIndex <= n && arr[rightIndex] > arr[largest]) {
        largest = rightIndex;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main() {
    int arr[6] = {-1, 54, 53, 55, 52, 50};  // Using index 1 to n
    int n = 5;  // Number of valid elements (excluding index 0)

    // Build heap (heapify all non-leaf nodes)
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Printing max heap array:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

