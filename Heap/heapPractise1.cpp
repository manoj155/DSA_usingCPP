#include<iostream>

using namespace std;

class Heap {
    public:

        int arr[101];
        int size;

        Heap() {
            size = 0;
        }

        void insert(int value) {
            //value insert karo end me
            size = size+1;
            int index = size;
            arr[index] = value;

            //iss value ko correct position me place karo
            while(index > 1) {
                int parentIndex = index/2;
                if(arr[parentIndex] < arr[index]) {
                    swap(arr[parentIndex], arr[index]);
                    index = parentIndex;
                }
                else {
                    break;
                }
            }
        }

        int deleteH() {
            int ans = arr[1]; 

            //replace last node value with root node value
            arr[1] = arr[size];
            size--;

            // place root at correct position
            int index = 1;
            while(index < size) {
                int leftChildIndex = 2*index;
                int rightChildIndex = 2*index + 1;

                int largest = index;
                if(leftChildIndex<size && arr[largest] < arr[leftChildIndex]) 
                    largest = leftChildIndex;
                if(rightChildIndex<size && arr[largest] < arr[rightChildIndex]) 
                    largest = rightChildIndex;

                if(index == largest)
                    break;
                else {
                    swap(arr[index], arr[largest]);
                    index = largest;
                }
            }
            return ans;
        }

        void heapify(int arr[], int n, int i) {
            int index = i;
            int leftIndex = 2*index;
            int rightIndex = 2*index+1;

            int largest = index;
            if(leftIndex<=n && arr[largest]<arr[leftIndex]) {
                largest = leftIndex;
            }
            if(rightIndex<=n && arr[largest]<arr[rightIndex]) {
                largest = rightIndex;
            }

            if(index!=largest) {
                swap(arr[index], arr[largest]);
                index = largest;
                heapify(arr, n, index);
            }
        }

        void buildHeap(int arr[], int n) {
                for(int i = n/2; i>0; i--) {
                        heapify(arr,n, i);
                }
        }

        void heapSort(int arr[], int n) {
                while(n != 1) {
                        swap(arr[1], arr[n--]);
                        heapify(arr,n,1);
                }
        } 
};

int main() {
    Heap h;
    int arr[] = {-1,12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};
    int n = 11;
    h.buildHeap(arr, n);

    cout << "printint the heap "<< endl;
    for(int i=0; i<=n; i++) {
            cout << arr[i] << " ";
    }
    cout << endl;

    h.heapSort(arr, n);

    cout << endl << "printint the heap "<< endl;
    for(int i=1; i<=n; i++) {
            cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}