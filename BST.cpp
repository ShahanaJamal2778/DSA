#include<iostream>
#include<cstdlib>
using namespace std;
struct BSTNode{
	int data;
	BSTNode* left;
	BSTNode* right;
	int height;
};

int height(BSTNode *root){
	if(node!=NULL)
	{return root->height;}
	else{
		return 0;
	}
	
}

int find_depth_of_node(BSTNode *root,int value){
	
	if(root==NULL){
		cout<<value<<"not foundin tree"<<endl;
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

BSTNode* insert(BSTNode* node,int value){
	if(node==NULL){
		BSTNode* temp=(BSTNode*)malloc(sizeof(BSTNode));
		temp->data=value;
		temp->left=NULL;
		temp->right=NULL;
		temp->height=1;
		return temp;
	}
	if(value>node->data){
		node->right=insert(node->right,value);
	}else{
		node->left=insert(node->left,value);
	}
	node->height=1+max()
	return node;
}

void search(BSTNode* root,int value){
	if(root==NULL){
		cout<<value<<" is not found"<<endl;
		return;
	}
	if(root->data==value){
		cout<<value<<" is found"<<endl;
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
	
void pre_order(BSTNode* node){
	if(node!=NULL){
		cout<<node->data<<endl;
		pre_order(node->left);
		pre_order(node->right);
		
	}
	
}

void in_order(BSTNode* node){
	
	if(node!=NULL){
		in_order(node->left);
		cout<<node->data<<endl;

		in_order(node->right);
		}
		}
		
		
void post_order(BSTNode* node){
		if(node!=NULL){
		post_order(node->left);
		post_order(node->right);
		cout<<node->data<<endl;
}
		}	
		
BSTNode* for_left_max(BSTNode* root){
	while(root->right!=NULL){
	root=root->right;}
		return root;
		
	
}

BSTNode* for_right_min(BSTNode* root){
	while(root->left!=NULL){
	root=root->left;}
		return root;
		
	
}

void delete_node(BSTNode* p_root,BSTNode* root,int value){
	//BSTNode* temp_parent=root;
	if(root==NULL){
		cout<<value<<" is not found"<<endl;
		return;
	}
	if(root->data==value){
		cout<<value<<" is found"<<endl;
			BSTNode* temp=root;
			BSTNode* temp_l=root->left;
			BSTNode* temp_r=root->right;
			if(temp_l==NULL&&temp_r==NULL){
				free(temp);
				return;
				}
			else if(temp_l==NULL && temp_r!=NULL){
 			cout << temp->data << " is deleted" << endl;
            if (p_root) {
                if (p_root->right == temp) p_root->right = temp_r;
              //  else p_root->left = temp_l;
            }
            free(temp);
            return;
							}
			
			else if(temp_r==NULL && temp_l!=NULL){
			
			 cout << temp->data << " is deleted" << endl;
            if (p_root) {
                if (p_root->left == temp) p_root->left = temp_l;
                //else p_root->right = temp_r;
            }
            free(temp);
            return;
			}
			else{
//			
				BSTNode* temp_left_max=for_left_max(temp->left);
	if (p_root) {
                if (p_root->left == temp) p_root->left = temp_left_max;;
                else p_root->right = temp_left_max;
            }
			//	p_root->left=temp_left_max;
				temp_left_max->left=temp->left;
				temp_left_max->right=temp->right;
			//	free(temp);
				delete_node(temp,temp->left,temp_left_max->data);
				free(temp);
				return;
	
//	BSTNode* temp_right_min=for_right_min(temp->right);
//	if (p_root) {
//                if (p_root->left == temp) p_root->left = temp_right_min;
//                else p_root->right = temp_right_min;
//            }
//			//	p_root->left=temp_left_max;
//				temp_right_min->left=temp->left;
//				temp_right_min->right=temp->right;
//			
//				delete_node(temp,temp->right,temp_right_min->data);
//				free(temp);
//				return;
//			}
//			}
	else{
		
		if(root->data<value){
		delete_node(root,root->right,value);
	}else{
			delete_node(root,root->left,value);	
	}
		}
	
}			
int main(){
	BSTNode* root=NULL;
	while(true){
	cout<<"enter key"<<endl;
	int choice;
	cin>>choice;
	switch(choice){
	case 1:
		cout<<"enter the  value to insert into tree"<<endl;
		int value;
		cin>>value;
		root=insert(root,value);
	break;
	case 2:
		cout<<"enter the  value to search in tree"<<endl;
		int value2;

		search(root,value2);
		break;
	case 3:
		cout<<"pre order"<<endl;
		pre_order(root);
		break;
	case 4:
		cout<<"in order"<<endl;
		in_order(root);
	
		break;
	case 5:
		cout<<"post order"<<endl;
		post_order(root);
		break;
	case 6:
			cout<<"enter the  value to delete from tree"<<endl;
		int value_d;
		cin>>value_d;
		delete_node(root,root,value_d);
		break;	
	case 7:
		break;			
}
}
	
}
