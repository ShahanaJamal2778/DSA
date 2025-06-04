
#include<iostream>
#include<cstdlib>
using namespace std;
struct LLNode{
	int data;
	LLNode *next;
	
}*start=NULL;


void insert(){//push
	LLNode *ptr=(LLNode*)malloc(sizeof(LLNode));
	
cout<<"enter value"<<endl;
cin>>ptr->data;
if(start==NULL){
	start=ptr;
}
else{
	LLNode* temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=ptr;
}

}

//void swap(){
//		int value_1;
//		int value_2;
//	cout<<"enter the values to be swept"<<endl;
//	cout<<"enter 1st value"<<endl;
//
//	cin>>value_1;
//	string ab=search(value_1);
//	if(ab=="value is not found"){
//			cout<<"value is not found";
//		return;
//	}else{
//		cout<<"enter 2nd value"<<endl;
//
//	cin>>value_2;
//	
//	string cd=search(value_2);
//	if(cd=="value is not found"){
//		cout<<"value is not found";
//		return;
//	}else{
//	if(value_1==value_2){
//		cout<<"both values are same"<<endl;
//		return;
//	}
//	LLNode * prev1=start;
//	LLNode * temp1=start->next;
//	LLNode * prev2=temp1;
//	LLNode * curr1=temp1->next;
//	LLNode * temp2=temp1->next;
//	if(value_1==start->data){
//		prev1->next=temp2->next;
//		temp2->next=temp1;
//		prev2->next=prev1;
//		
//	
//	}else if(value_2==curr1->data){
//	temp1->next=temp2->next;
//	temp2->next=temp1;
//	prev1->next==temp2;
//	}else{
//		//while(temp2!=NULL){
//		while(temp1->data==value_1){
//		temp1=temp1->next;
//		curr1=curr1->next;
//		prev1=prev1->next;
//		
//		}	
//		while(temp2->data==value_2){
//		temp2=temp2->next;
//		prev2=prev2->next;
//		
//		}
//		temp1->next=temp2->next;
//		temp2->next=curr1;
//		prev1->next=temp2;
//		prev2->next=temp1;
//		return;
//		
//		}
//		}
//		}
//	}

void swap() {
    if (start == NULL || start->next == NULL) {
        cout << "List is too short to swap." << endl;
        return;
    }

    int value_1, value_2;
    cout << "Enter the values to be swapped" << endl;
    cout << "Enter 1st value: ";
    cin >> value_1;
    cout << "Enter 2nd value: ";
    cin >> value_2;

    if (value_1 == value_2) {
        cout << "Both values are the same, no swap needed." << endl;
        return;
    }

    // Find nodes with value_1 and value_2
    LLNode *prev1 = NULL, *prev2 = NULL;
    LLNode *node1 = start, *node2 = start;

    while (node1 && node1->data != value_1) {
        prev1 = node1;
        node1 = node1->next;
    }

    while (node2 && node2->data != value_2) {
        prev2 = node2;
        node2 = node2->next;
    }


    if (!node1 || !node2) {
        cout << "One or both values not found." << endl;
        return;
    }

    // Swap previous node links
    if (prev1) prev1->next = node2;
    else start = node2; 

    if (prev2) prev2->next = node1;
    else start = node1;  
    
    LLNode *temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;

    cout << "Nodes swapped successfully!" << endl;
}

void todelete(){
int todel;
cout<<"Enter the value to be deleted";
cin>>todel;
if(start->data==todel){
	LLNode * temp=start;
	start =start->next;
	free(temp);
}else{
	LLNode * prev=start;
	LLNode * curr=start->next;
	while(curr!=NULL){
		if(curr->data==todel){
			prev->next=curr->next;
			free(curr);
			return;
		}
		curr=curr->next;
		prev=prev->next;
	}
	
}
}

void Insert_AT_multiple_of_three(){
	int num;
	int c=1;

	cout<<"enter a multiple of three: "<<endl;
		cin>>num;
		int remainder=num%3;
		cout<<remainder;
		if(remainder==0){
				LLNode *ptr=(LLNode*)malloc(sizeof(LLNode));
	        ptr->data=num;
if(start==NULL){
	start=ptr;
	return;
}
else{
	LLNode* temp=start;
	while(temp!=NULL)
	{
		temp=temp->next;
	}
	temp->next=ptr;
		return;
}
		
	}
	else{
	
if(start==NULL){
    	LLNode *ptr2=(LLNode*)malloc(sizeof(LLNode));
	start=ptr2;
	 ptr2->next=NULL;
	ptr2->data=num;
	return;
}
else{
	LLNode* temp=start;
	while(temp->next!=NULL)
	{ 
		if (c%remainder==0){
	//	   if(c)
	//	    ptr->next=temp->next;
	//		temp->next=ptr;
	//		cout<<ptr->data<<endl;
	//		cout<<c<<endl;
	//	   }else{
		       	LLNode *ptr2=(LLNode*)malloc(sizeof(LLNode));
		       ptr2->next=temp->next;
		       	ptr2->data=num;
			temp->next=ptr2;
			cout<<ptr2->data<<endl;
			cout<<c<<endl; 	
		   temp=ptr2->next;
		   c=1;
			
			
		}else{
		temp=temp->next;
		c++;
	
	}
		
	//	if(c==remainder){
	//	    temp=temp->next->next;
	//	    c=1;
	//	}
		
	    
	}
		if(temp->next==NULL){
		    	LLNode *ptr2=(LLNode*)malloc(sizeof(LLNode));
		       ptr2->next=temp->next;
		       	ptr2->data=num;
			temp->next=ptr2;
			cout<<ptr2->data<<endl;
		}
    
}
	
}
}		
		

void print(){
	LLNode * temp=start;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	}
	
string search(int tosearch){
	//int tosearch;
//	cin>>tosearch;
	LLNode *temp=start;
	while(temp!=NULL){
		if(temp->data==tosearch){
	//		cout<<"value is found"<<endl;
			return "value is found";
		}
		temp=temp->next;
		}
	//	cout<<"value is not found"<<endl;
		return "value is not found";
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
			{	cout<<"enter the value to be searched"<<endl;
		int tosearch;
		cin>>tosearch;
	    string temp=search(tosearch);
	    cout<<temp;
		break;}
	case 3:
		print();
		break;
	case 4:
		
		Insert_AT_multiple_of_three();
			break;	
	case 5:
		
		todelete();	
		break;
	case 6:
		swap();	
			break;
		
	
}}
else{
	break;
}
}


}
