#include<iostream>
#include<queue>
using namespace std;

int kthGreatestElement(int arr[], int n, int k) {
    //create a min heap
    priority_queue<int, vector<int>, greater<int> > pq;
    //insert starting k elements in the heap
    for(int i =0; i<k; i++) {
        pq.push(arr[i]);
    }
    //for remaining n-k elements push only if the element is greater than pq.top()
    for(int i=k; i<n; i++) {
        if(arr[i]>pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int kthSmallestElement(int arr[], int n, int k) {
    //create a max heap
    priority_queue<int> pq;
    //insert starting k elements in the heap
    for(int i =0; i<k; i++) {
        pq.push(arr[i]);
    }
    //for remaining n-k elements push only if the element is smaller than pq.top()
    for(int i=k; i<n; i++) {
        if(arr[i]<pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main() {
    int arr[] = {10,5,20,4,15};
    int n = 5;
    int k = 2;
    int ans = kthSmallestElement(arr, n, k);
    cout << "K-th smallest element is: " << ans << endl;

    cout << "K-th greatest element is: " << kthGreatestElement(arr, n, k) << endl;
    return 0;
}