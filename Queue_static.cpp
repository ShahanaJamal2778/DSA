#include<iostream>
using namespace std;
int stack[4];	
int front=-1;
int rear=-1;
int size=sizeof(stack)/sizeof(stack[0]);

void push(int value){
	if((rear+1)%size==front){
		cout<<"stack overflow"<<endl;
		return;
	}
	if(rear==-1){
	rear=0;
	front=0;
}else{
	rear=(rear+1)%size;
}
	stack[rear]=value;
	}


int pop(){
		int temp=stack[front];
			
	if(front==-1){
		cout<<" stack under flow"<<endl;
		return 0;
	}
	if(front==rear){
		front=-1;
		rear=-1;
	
	}

	front=(front+1)%size;
	return temp;

}

void print(){
	int i=front;
	while(true){
		cout<<stack[i]<<endl;
			if(i==rear){
			break;
		}
		i=(i+1)%size;
		
	}
}

int main(){
	int choice;
	while(choice!=3){
	
	cout<<"enter 1 to push and 2 to pop,3 to print and 4 to exit "<<endl;
	cin>>choice;
	switch(choice){
		case 1:
			cout<<"enter the value to be pushed"<<endl;
			int value;
			cin >>value;
			push(value);
			break;
		case 2:
		cout<<"value to be popped"<<pop()<<endl;
			break;;
		case 3:
			print();
			break;	
		case 4:
			break;		
	}

}
	
}

