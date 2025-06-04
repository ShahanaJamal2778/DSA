#include<iostream>
#include<cstdlib>
using namespace std;
struct AVLNode{
	int data;
	AVLNode* left;
	AVLNode* right;
	int height;
};

int height(AVLNode* node){
	if(node==NULL)
	return 0;
	else{
	
	return node->height;}
}

int get_balance_factor(AVLNode* node){
	return height(node->left)-height(node->right);
	
	
}
int max (int a, int b){
	return (a>b)? a:b;
}


AVLNode* right_rotate(AVLNode* node){
	AVLNode* x=node->left;
		AVLNode* remain=x->right;
		node->left=remain;
		x->right=node;
		node->height=1+max(height(node->left),height(node->right));
		x->height=1+max(height(x->left),height(x->right));
		return x;
}

AVLNode* left_rotate(AVLNode* node){
	AVLNode* x=node->right;
		AVLNode* remain=x->left;
		node->right=remain;
		x->left=node;
		node->height=1+max(height(node->left),height(node->right));
		x->height=1+max(height(x->left),height(x->right));
		return x;	
	
}




AVLNode* insert(AVLNode* node,int value){
	if(node==NULL){
		AVLNode* temp=(AVLNode*)malloc(sizeof(AVLNode));
		temp->data=value;
		temp->left=NULL;
		temp->right=NULL;
		temp->height=1;
		return temp;
	}
	if(value>node->data){
		node->right=insert(node->right,value);
		
		node->height=1+max(height(node->left),height(node->right));
		int b_f=get_balance_factor(node);
		
		if(b_f>1 && value < node->left->data)
		{ //right rotate
		AVLNode* x=right_rotate(node);
		return x;}
		
		
		if(b_f<-1 && value>node->right->data){
//			left rotate
			AVLNode* x=left_rotate(node);
			return x;}
			
			
		if(b_f>1 &&value>node->left->data)
		{ //left rotate right rotate
		node->left=left_rotate(node->left);
		AVLNode* x=right_rotate(node);
		
		return x;}
		
		
		if(b_f<-1 && value<node->right->data){
//		right rotate left rotate
			node->right=right_rotate(node->right);
			AVLNode* x=left_rotate(node);
			return x;}	
		
		
		
	}else{
		node->left=insert(node->left,value);
		node->height=1+max(height(node->left),height(node->right));
		
		int b_f=get_balance_factor(node);
		
		if(b_f>1 &&value<node->left->data)
		{ //right rotate
		AVLNode* x=right_rotate(node);
		return x;}
		
		
		if(b_f<-1 && value>node->right->data){
//			left rotate
			AVLNode* x=left_rotate(node);
			return x;}
	
		if(b_f>1 &&value>node->left->data)
		{ //left rotate right rotate
		node->left=left_rotate(node->left);
		AVLNode* x=right_rotate(node);
		
		return x;}
		
		
		if(b_f<-1 && value<node->right->data){
//		right rotate left rotate
			node->right=right_rotate(node->right);
			AVLNode* x=left_rotate(node);
			return x;}	
		
		
	}
	
	return node;
	

	
	
}

void search(AVLNode* root,int value){
	if(root==NULL){
		cout<<value<<" is not found"<<endl;
		return;
	}
	if(root->data==value){
			int b_f=get_balance_factor(root);
		cout<<value<<" is found at "<<root->height<<" and having balance factor "<<b_f<<endl;
	
		return;
	}
	else{
		
		if(root->data<value){
			search(root->right,value);
	}else{
		search(root->left,value);
	}
		}
	}

int main(){
	AVLNode* root=NULL;
	for(int i=0;i<10;i++){
	
	cout<<"enter the  value to insert into tree"<<endl;
		int value;
		cin>>value;
		root=insert(root,value);}
		
		
		for(int i=0;i<10;i++){
			cout<<"enter the  value to search into tree"<<endl;
		int value1;
		cin>>value1;
		search(root,value1);
		}
		
		
}
