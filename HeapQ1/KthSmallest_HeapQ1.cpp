#include<iostream>
#include<queue>
using namespace std;
// l: starting index
// r: ending index
// Function to find the Kth smallest element in arr[l..r]
int KthSmallest(int arr[], int l, int r, int k){
	// Max heap to store k smallest elements
	priority_queue<int> pq;
	//step 1 Insert first k elements from l
	for(int i = 0 ; i<l+k; i++){
		pq.push(arr[i]);
	}
	//step 2 Traverse remaining elements from arr[l+k..r]
	for(int i=l+k; i<=r; i++){
		if(arr[i]<pq.top()){
			pq.pop();
			pq.push(arr[i]);
		}
	}
	// Step 3: Return the top of the heap (Kth smallest)
	return pq.top();
}
int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = 6; 
    int k = 3;
    int result = KthSmallest(arr, 0, n - 1, k);
    cout << "Kth Smallest Element: " << result << endl;
    return 0;
}
