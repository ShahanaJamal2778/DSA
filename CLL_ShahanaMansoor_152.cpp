
#include<iostream>
#include<cstdlib>
using namespace std;
struct LLNode{
	int data;
	LLNode *next;
	
}*start=NULL;



void todelete(){
int todel;
cout<<"Enter the value to be deleted";
cin>>todel;
if(start->data==todel){
	LLNode* temp2=start->next;
	while(temp2->next!=start)
	{
		temp2=temp2->next;
	}
	LLNode * temp=start;
	start =start->next;
	temp2->next=start;
	free(temp);
	return;
	}else{
	LLNode * prev=start;
	LLNode * curr=start->next;
	while(curr!=start){
		if(curr->data==todel){
			prev->next=curr->next;
			free(curr);
			return;
		}
		curr=curr->next;
		prev=prev->next;
	}
	
	if(curr==start){
		cout<<"value is not found";
	}
	
}
}


void insert(){
	LLNode *ptr=(LLNode*)malloc(sizeof(LLNode));
	
cout<<"enter value"<<endl\;
cin>>ptr->data;
if(start==NULL){
	start=ptr;

}
else{
	LLNode* temp=start;
	while(temp->next!=start)
	{
		temp=temp->next;
	}
	temp->next=ptr;p
}
ptr->next=start;
}




void print(){
	LLNode * temp=start;
do{
		cout<<temp->data<<" ";
		temp=temp->next;
	}	
	while(temp!=start);
	
}
void search(){
	int tosearch;
	cin>>tosearch;
	LLNode *temp=start;
		do{
		
		if(temp->data==tosearch){
			cout<<"value is found"<<endl;
			return;
		}
		temp=temp->next;
		}while(temp!=start);
		cout<<"value is not found"<<endl;
}	
	
int main(){
	


while(true){
int choice;
cout<<"enter digit"<<endl;
cin>>choice;

if(choice!=0){
switch(choice){
	case 1:
		insert();
		break;
	case 2:
		search();
		break;
	case 3:
		print();
		break;
	case 4:
		todelete();
		break;	
	
}}
else{
	break;
}
}


}
