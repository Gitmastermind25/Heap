#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int leftindex = 2 * i + 1;
    int rightindex = 2 * i + 2;

    if (leftindex < n && arr[leftindex] < arr[smallest]) {
        smallest = leftindex;
    }
    if (rightindex < n && arr[rightindex] < arr[smallest]) {
        smallest = rightindex;
    }

    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

int main() {
    int arr[] = {54, 53, 55, 52, 50};
    int n = 5;

    // Build Min Heap (start from last non-leaf node)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Printing Min Heap array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

