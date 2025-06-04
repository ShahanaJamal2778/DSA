#include<iostream>
#include<string>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
} *root = NULL;

Node* stack[10];  // stack of pointers to Node
int top = 0;

void push(Node* value) {
    if (top == sizeof(stack) / sizeof(stack[0])) {
        cout << "Stack overflow" << endl;
        return;
    }
    stack[top++] = value;
}

Node* pop() {
    if (top == 0) {
        cout << "Stack underflow" << endl;
        return NULL;
    }
    return stack[--top];
}

char stack2[10];	

void push_ch(char value){
	if(top==sizeof(stack)/sizeof(stack[0])){
		cout<<"stack overflow"<<endl;
		return;
	}
	stack2[top++]=value;
}

char pop_ch(){
	if(top==0){
		cout<<" stack under flow"<<endl;
		return '\0';

	}
	top--;
	return stack2[top];
}

int precedence(char operand){
	if(operand=='*' ||operand=='/' ||operand=='%' ){
		return 2;
	}
	if(operand=='+' ||operand=='-'){
		return 1;
	}
	return 0;
}

bool isempty(){
	if(top==0){
		return false;
	}else{return true;
	}}

string infix_To_Postfix(){
cout<<"enter infix string"<<endl;
string str;
cin>>str;
string postfix="";
for(int i=0;i<str.length();i++){
	
	if((str[i]>='a' && str[i]<='z') || (str[i]>='1' && str[i]<='9')){
		postfix+=str[i];
	}
	else if(str[i]=='('){
		push_ch(str[i]);}
	else if(str[i]==')'){
		while(stack2[top-1]!='('&&isempty()){
			postfix+=pop_ch();
				
			}
			pop_ch();
			
		}else{
		
		while(precedence(str[i])<=precedence(stack2[top-1])&&isempty()){
		postfix+=pop_ch();	
			
		}
		push_ch(str[i]);
		
	}
	
	
}

while(isempty()){
	postfix+=pop_ch();	
}
for(int i=0;i<postfix.length();i++){
	cout<<postfix[i]<<" ";
}
return postfix; 	
}

void post_order(Node* node){
		if(node!=NULL){
		post_order(node->left);
		post_order(node->right);
		cout<<node->data;
}
		}	
		
int main() {
//    cout << "Enter postfix expression (lowercase letters):" << endl;
    string str=infix_To_Postfix();
//    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            Node* temp = new Node();
            temp->data = str[i];  // storing character as int
            temp->left = temp->right = NULL;
            push(temp);
        } else {
            Node* temp = new Node();
            temp->data = str[i];  // operator as int (optional)
            temp->right = pop();
            temp->left = pop();
            push(temp);
        }
    }

    root = pop();
    if (root != NULL){
	
        cout << "Root node data: " << root->data << endl;
        cout<<"post order"<<endl;
		post_order(root);}
    else{
	
        cout << "Invalid expression or empty tree." << endl;
}
	    

    return 0;
}

