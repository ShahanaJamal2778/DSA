#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
struct BSTNode{
	int data;
	BSTNode* left;
	BSTNode* right;
	int height;
};
BSTNode *root=NULL;

int height(BSTNode *root){
	if(root!=NULL)
	{return root->height;}
	else{
		return 0;
	}
	
}

int max(int a,int b){
	return (a>b)? a:b;
}

int depth_of_tree(BSTNode *root){
		if(root==NULL){
			cout<<"depth of tree is 0"<<endl;
		return 0;
	}
	else{
		cout<<"depth of tree is "<<height(root)<<endl;
		return height(root);
	}
}

int find_depth_of_node(BSTNode *root,int value){
	if(root==NULL){
		cout<<value<<"not found in tree"<<endl;
		return 0;
	}
	if(root->data==value){
		cout<<value<<" is found tree"<<endl;
		return height(root);
	}
	else{
		
		if(root->data<value){
			find_depth_of_node(root->right,value);
	}else{
		find_depth_of_node(root->left,value);
	}
		}
	
}

int cout_duplicate[10];
BSTNode* insert_with_duplicates(BSTNode* node,int value){
	
//	int value_dup[10];
	if(node==NULL){
		BSTNode* temp=(BSTNode*)malloc(sizeof(BSTNode));
		temp->data=value;
		temp->left=NULL;
		temp->right=NULL;
		temp->height=1;
		return temp;
	}
		if(value==node->data){ cout_duplicate[value%10]++;}
	else if(value>node->data){
	node->right=insert_with_duplicates(node->right,value);}
	else{
		node->left=insert_with_duplicates(node->left,value);
	}
	node->height=1+max(height(node->right),height(node->left));
	return node;
}


		
BSTNode* for_left_max(BSTNode* root){
	while(root->right!=NULL){
	root=root->right;}
		return root;
		
	
}



void delete_node(BSTNode* p_root,BSTNode* root,int value){
	if(root==NULL){
		cout<<value<<" is not found"<<endl;
		return;
	}
	if(root->data==value){
		cout<<value<<" is found"<<endl;
		for(int i=0;i<10;i++){
			if(cout_duplicate[i]!=-1){
				if(i==value%10){
					cout<<"this value is duplicated for"<<cout_duplicate[i]<<" times"<<endl;
					cout_duplicate[i]--;
					return;
				}
			}
		}
			BSTNode* temp=root;
			if(temp->left==NULL&&temp->right==NULL){
				p_root->height=1+max(height(p_root->right),height(p_root->left));
				free(temp);
				return;
				}
			else if(temp->left==NULL){
 			cout << temp->data << " is deleted" << endl;
            if (p_root) {
                if (p_root->right == temp) p_root->right = temp->right;
              else{ p_root->left=temp->right;}
            }
            	p_root->height=1+max(height(p_root->right),height(p_root->left));
            free(temp);
            return;}
			
			else{
			cout << temp->data << " is deleted" << endl;
           	BSTNode* temp_left_max=for_left_max(temp->left);
           	temp->data=temp_left_max->data;
           	p_root->height=1+max(height(p_root->right),height(p_root->left));
           	delete_node(root,root,temp_left_max->data);
            return;
			}
	}
	else{
		
		if(root->data<value){
		delete_node(root,root->right,value);
	}else{
			delete_node(root,root->left,value);	
	}
		}
	
}

queue<BSTNode*> q;
void traversal(BSTNode *root){
	q.push(root);
	while(!q.empty()){
		BSTNode *front=q.front();
			for(int i=0;i<10;i++){
			if(cout_duplicate[i]!=-1){
				if(i==front->data%10){
					cout<<"this value is duplicated for"<<cout_duplicate[i]<<" times"<<endl;
					cout_duplicate[i]--;	
				}
			}
		cout<<front->data<<" ";
		q.pop();
		if(front->left!=NULL || front->right!=NULL){

		if(front->left!=NULL && front->right!=NULL){
			q.push(front->left);	q.push(front->right);
		}else if(front->left==NULL){
				q.push(front->right);
		}else{
				q.push(front->left);
		}}
	}
	
	
}}


			
int main()
{
	
	while(true){
	cout<<"enter key"<<endl;
	int choice;
	cin>>choice;
	switch(choice){
	case 1:
		cout<<"enter the  value to insert into tree"<<endl;
		int value;
		cin>>value;
		root=insert_with_duplicates(root,value);
	break;
	case 2:
	depth_of_tree(root);
		break;
	case 3:
		cout<<"enter the  value to find depthof node"<<endl;
		int value1;
		cin>>value1;
		find_depth_of_node(root,value1);
	break;
					
	case 4:
			cout<<"enter the  value to delete from tree"<<endl;
		int value_d;
		cin>>value_d;
		delete_node(root,root,value_d);
		break;	
	case 5:
		traversal(root);
		break;			
}
}
return 0;	
}
