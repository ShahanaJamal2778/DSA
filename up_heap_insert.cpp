#include<iostream>
#include<cstdlib>
using namespace std;

// const int size=10

int arr[10];
int count = 0;

void swap(int arr[], int n1, int n2) {
    int t = arr[n1];
    arr[n1] = arr[n2];
    arr[n2] = t;
}

void up_heapify(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (arr[parent] < arr[index]) {
            swap(arr, parent, index);
            index = parent;
        } else {
            break;
        }
    }
}

void insert() {
    int value;
    for (int i = 0; i < 10; i++) {
        if (count >= 10) {
            cout << "Heap is full!" << endl;
            break;
        }

        cout << "Enter value " << (i + 1) << ": ";
        cin >> value;
        arr[count] = value;
        up_heapify(count);
        count++;
    }
}


void print(){
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
}

void down_heapify() {
    int i = 0;

    while (true) {
        int l_child = 2 * i + 1;
        int r_child = 2 * i + 2;
        int largest = i;

        if (l_child < count && arr[l_child] > arr[largest])
            largest = l_child;

        if (r_child < count && arr[r_child] > arr[largest])
            largest = r_child;

        if (largest != i) {
            swap(arr, i, largest);  // Fix: use index, not values
            i = largest;
        } else {
            break;
        }
    }
}

void delete_heap() {
    if (count == 0) {
        cout << "Heap is empty!" << endl;
        return;
    }

    swap(arr, 0, count - 1);  // Move max to end
    count--;                  // Shrink heap
    down_heapify();          // Restore heap property
}

void sorted_heap() {
    cout << "Sorted Heap (Descending):" << endl;

    int originalCount = count;

    for (int i = 0; i < originalCount; i++) {
        cout << arr[0] << " ";
        delete_heap();  // Deletes the max and heapifies
    }
    cout << endl;
}



// void down_heapify() {
//     int i = 0;

//     while (true) {
//         int l_child = 2 * i + 1;
//         int r_child = 2 * i + 2;
//         int largest = i;

//         if (l_child < count && arr[l_child] > arr[largest])
//             largest = l_child;

//         if (r_child < count && arr[r_child] > arr[largest])
//             largest = r_child;

//         if (largest != i) {
//             swap(arr,arr[i], arr[largest]);
//             i = largest;
//         } else {
//             break;
//         }
//     }
// }

// void delete_heap() {
//     if (count == 0) {
//         cout << "Array is empty now" << endl;
//         return;
//     }

    
// 	swap(arr,arr[0],arr[count-1]);   // Move last element to root
//           // Optional: clear last
//     count--;                   // Decrease heap size
//     down_heapify();           // Restore heap property
// }	

// void sorted_heap(
// 	cout<<"sorted heap"<<endl;
// 	for(int i=0;i<count;i++){
//     delete_heap();}
// 	print();
	
// }

int main(){
    while(true){
	int choice;
	cout<<"enter key"<<endl;
	cin>>choice;
	switch(choice){
	case 1:
	insert();
	break;
	case 2:
	print();
	break;
	case 3:
	delete_heap();
	break;
	case 4:
	sorted_heap();
	break;
	case 5:
	break;
		
}
    }

	
}
