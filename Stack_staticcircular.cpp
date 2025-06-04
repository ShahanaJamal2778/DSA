#include<iostream>
using namespace std;
int stack[10];	
int top=0;
void push(int value){
	if(top==sizeof(stack)/sizeof(stack[0])){
		cout<<"stack overflow"<<endl;
		return;
	}
	stack[top++]=value;
}

int pop(){
	if(top==0){
		cout<<" stack under flow"<<endl;
		return 0;
	}
	top--;
	return stack[top];
}

void print(){
	for(int i=0;i<top;i++){
		cout<<stack[i]<<endl;
		
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

