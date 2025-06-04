#include <iostream>
#include<cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
};

const int size = 10;
Node* hashtable[size] = {NULL};  

void insert(int key) {
    int ind = key % size;

    
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = key;
    temp->next = NULL;

    if (hashtable[ind] == NULL) {
        hashtable[ind] = temp;
        return;
    }

    
    Node* temp1 = hashtable[ind];
    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    temp1->next = temp;
}


void print() {
    for (int i = 0; i < size; i++) {
      //  cout << "Bucket " << i << ": ";
        Node* temp = hashtable[i];
        while (temp!=NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}


void search(){
		cout<<"ente the number to search"<<endl;
int value;
cin>>value;
		for(int i=0;i<size;i++){
			 Node* temp = hashtable[i];
        while (temp!=NULL) {
            if(temp->data==value){
            	cout<<"value is found "<<endl;
            	return;
			}
            temp = temp->next;
        }
			
			
		}
	}
	






int main() {
	
	int choice=1;
while(choice!=0){

cout<<"enter the key 0 to exit"<<endl;
cin>>choice;
switch(choice){
	case 1:
		{
		while(true){
	cout<<"ente the number to insert and zero to exit"<<endl;
int value;
cin>>value;
	if(value==0){
		break;
	}else{
	
	insert(value);}
}
	break;}
	case 2:
		print();
		break;
	case 3:
		search();
		break;

	}
	
	}
//    insert(78);
//    insert(45);
//    insert(53);
//    insert(118);
//    insert(218);
//    insert(78);
//    insert(45);
//    insert(53);
//    insert(118);
//    insert(218);
//    insert(78);
//    insert(45);
//
//    print();
//    
    
}

