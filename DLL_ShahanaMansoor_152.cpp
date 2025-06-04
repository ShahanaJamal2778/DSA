`
#include<iostream>
#include<cstdlib>
using namespace std;
struct DLNode{
	int data;
	DLNode *next;
	DLNode *previous;
}*start=NULL;


void todelete(){
int todel;
cout<<"Enter the value to be deleted";
cin>>todel;
if(start->data==todel){
	DLNode * temp=start;
	start =start->next;
	free(temp);
	start->previous=NULL;
}else{
	DLNode * prev=start;
	DLNode * curr=start->next;
	while(curr!=NULL){
		if(curr->data==todel){
			prev->next=curr->next;
			curr->next->previous=prev;
			free(curr);
			return;
		}
		curr=curr->next;
		prev=prev->next;
	}
	
}
}

void reverse(){
		DLNode * temp=start;
	while(temp->next!=NULL){
	
		temp=temp->next;
	}
	while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->previous;
	}
}	
void insert(){
	DLNode *ptr=(DLNode*)malloc(sizeof(DLNode));
	
cout<<"enter value"<<endl;
cin>>ptr->data;
if(start==NULL){
	start=ptr;
	ptr->previous=NULL;
}
else{
	DLNode* temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	ptr->previous=temp;
	temp->next=ptr;
}

}


void print(){
	DLNode * temp=start;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	}
	
void search(){
	int tosearch;
	cin>>tosearch;
	DLNode *temp=start;
	while(temp!=NULL){
		if(temp->data==tosearch){
			cout<<"value is found"<<endl;
			return;
		}
		temp=temp->next;
		}
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
		reverse();	
			break;
	case 5:
		todelete();	
			break;
	
}}
else{
	break;
}
}


}
