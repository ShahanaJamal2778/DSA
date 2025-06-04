#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node  *right;
}*root=NULL;


//void insert(Node *root,int value){
void insert(int val){
	Node *ptr=(Node*)malloc(sizeof(Node));
	ptr->data=val;
//	cout<<"enter value"<<endl;
//cin>>ptr->data;
if(root==NULL){
	
	root=ptr;
	
	return;}
	else{
			Node *temp=root;
		while (temp->left != NULL || temp->right != NULL) {
        if (val < temp->data) {
         //   if (temp->left == NULL) break; 
			// Stop if we reach insertion point
            temp = temp->left; 
				cout<<"left"<<temp->data<<endl; // Move left
        } else {
           // if (temp->right ==NULL) break; // Stop if we reach insertion point
            temp = temp->right;
				cout<<"left"<<temp->data<<endl; // Move right
        }
    }
    if(temp->left==NULL){
    	temp->left=ptr;
    	cout<<"left"<<temp->data<<endl;
	}
	if(temp->right==NULL){
    	temp->right=ptr;
    		cout<<"right"<<temp->data<<endl;
	}
	}
	
//	else if(root->data>value){
//		insert(root->left,value);
//	else{
//	insert(root->right,value);	
//	}	
//	}
//	
}

int main(){
int arr[10]={2,45,6,7,90,34,38,50,100,134};	
for(int i=0;i<10;i++){

	insert(arr[i]);
}
	
	
}
