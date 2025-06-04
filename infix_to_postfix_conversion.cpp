#include<iostream>
#include<string>
using namespace std;
char stack[10];	
int top=0;
void push(char value){
	if(top==sizeof(stack)/sizeof(stack[0])){
		cout<<"stack overflow"<<endl;
		return;
	}
	stack[top++]=value;
}

char pop(){
	if(top==0){
		cout<<" stack under flow"<<endl;
		return '\0';

	}
	top--;
	return stack[top];
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
	}
}

int main(){
cout<<"enter infix string"<<endl;
string str;
cin>>str;

string postfix="";
for(int i=0;i<str.length();i++){
	
	if((str[i]>='a' && str[i]<='z') || (str[i]>='1' && str[i]<='9')){
		postfix+=str[i];
	}
	else if(str[i]=='('){
		push(str[i]);}
	else if(str[i]==')'){
		while(stack[top-1]!='('&&isempty()){
		postfix+=pop();
				
			}
			pop();
			
		}else{
		
		while(precedence(str[i])<=precedence(stack[top-1])&&isempty()){
		postfix+=pop();	
			
		}
		push(str[i]);
		
	}
	
	
}

while(isempty()){
	postfix+=pop();	
}
for(int i=0;i<postfix.length();i++){
	cout<<postfix[i]<<" ";

	
}
}
