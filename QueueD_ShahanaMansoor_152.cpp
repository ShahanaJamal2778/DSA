#include<iostream>
using namespace std;

struct QNode{
	int data;
	QNode* next;
}*front=NULL,*rear=NULL;

void Enqueue(int value){
	QNode* ptr=(QNode*)malloc(sizeof(QNode));
	ptr->data=value;
	ptr->next=NULL;
	if(front==NULL){
		front=ptr;
		rear=ptr;}
		else{
			rear->next=ptr;
			rear=ptr;
		}
	cout<<"Enqueued value"<<value<<endl;
		  
	}

int Dequeue(){
	if(front==NULL){
		cout<<"stack underflow"<<endl;
		return 0;
	}
	int toppedvalue=front->data;
	QNode *ptr=front;
	front=front->next;
	if(front==NULL){
		rear=NULL;
	}
	free(ptr);
	return toppedvalue;
	 
}

void print(){
    QNode *temp=front;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
        
    }
}
int main(){
	int choice;
	while(choice!=3){
	cout<<"enter 1 to Enqueue value in Queue,2 to Dequque 3 to print and 4 to exit"<<endl;

	cin>>choice;
	switch(choice){
		case 1:
			cout<<"enter value to be enqueued"<<endl;
			int value; 
			cin>>value;
			Enqueue(value);
			break;
		case 2:
			cout<<"dequeued "<<Dequeue()<<endl;
			break;
		case 3:
		    print();
			break;	
		case 4:
			break;	
				
		
	}}
                                                                                                                                                                                                                                       	
	
	
	
	
}
