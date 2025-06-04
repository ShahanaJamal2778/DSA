#include<iostream>
using namespace std;
struct SNode{
	int data;
	SNode* next;
}*top=NULL;

void push(int value){
	SNode* ptr=(SNode*)malloc(sizeof(SNode));
	ptr->data=value;
	ptr->next=top;
	top=ptr;
	cout<<"push value"<<value<<endl;
		  
	}

int pop(){
	if(top==NULL){
		cout<<"stack underflow"<<endl;
		return 0;
	}
	int toppedvalue=top->data;
	SNode *ptr=top;
	top=top->next;
	free(ptr);
	return toppedvalue;
	 
}

void print(){
    SNode *temp=top;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
        
    }
}
int main(){
	int choice;
	while(choice!=3){
	cout<<"enter 1 to push value in stack,2 to pop and 3 to exit"<<endl;

	cin>>choice;
	switch(choice){
		case 1:
			cout<<"enter value to be pushed"<<endl;
			int value; 
			cin>>value;
			push(value);
			break;
		case 2:
			cout<<"popped "<<pop()<<endl;
			break;
		case 3:
		    print();
			break;	
		case 4:
			break;	
				
		
	}}
                                                                                                                                                                                                                                       	
	
	
	
	
}
