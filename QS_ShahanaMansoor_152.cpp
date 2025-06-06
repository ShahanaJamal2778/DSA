#include<iostream>
#include<cstdlib>
using namespace std;

void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Partition function//java style int[] arr
int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return (i + 1);
    }

    // QuickSort function
void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    void printArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            cout<<arr[i]<<" "<<endl;
        }
    
    }
int main(){
	 int arr[] = {10, 7, 8, 9, 1, 5};
        int n = sizeof(arr)/sizeof(arr[0]);
        cout<<"Original array: "<<endl;
        printArray(arr, n);

        quickSort(arr, 0, n - 1);

        cout<<"Sorted array: "<<endl;
        printArray(arr, n);
	
	
	
	
	
}
