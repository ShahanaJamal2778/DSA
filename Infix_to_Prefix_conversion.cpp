//#include<iostream>
//#include<string>
//using namespace std;
//char stack[10];	
//int top=0;
//void push(char value){
//	if(top==sizeof(stack)/sizeof(stack[0])){
//		cout<<"stack overflow"<<endl;
//		return;
//	}
//	stack[top++]=value;
//}
//
//char pop(){
//	if(top==0){
//		cout<<" stack under flow"<<endl;
//		return '\0';
//
//	}
//	top--;
//	return stack[top];
//}
//
//int precedence(char operand){
//	if(operand=='*' ||operand=='/' ||operand=='%' ){
//		return 2;
//	}
//	if(operand=='+' ||operand=='-'){
//		return 1;
//	}
//	return 0;
//}
//
//bool isempty(){
//	if(top==0){
//		return false;
//	}else{return true;
//	}
//}
//
//int main(){
//cout<<"enter infix string"<<endl;
//string str;
//cin>>str;
//
//string postfix="";
//for(int i=0;i<str.length();i++){
//	
//	if((str[i]>='a' && str[i]<='z') || (str[i]>='1' && str[i]<='9')){
//		postfix+=str[i];
//	}
//	else if(str[i]=='('){
//		push(str[i]);}
//	else if(str[i]==')'){
//		while(stack[top-1]!='('&&isempty()){
//		postfix+=pop();
//				
//			}
//			pop();
//			
//		}else{
//		
//		while(precedence(str[i])<=precedence(stack[top-1])&&isempty()){
//		postfix+=pop();	
//			
//		}
//		push(str[i]);
//		
//	}
//	
//	
//}
//
//while(isempty()){
//	postfix+=pop();	
//}
//for(int i=postfix.length();i>=0;i--){
//	cout<<postfix[i]<<" ";
//
//	
//}
//}



#include <iostream>
#include <string>
#include <algorithm> // for reverse
using namespace std;

char stack[50];
int top = 0;

void push(char value) {
	if (top == sizeof(stack)/sizeof(stack[0])) {
		cout << "stack overflow" << endl;
		return;
	}
	stack[top++] = value;
}

char pop() {
	if (top == 0) {
		cout << "stack underflow" << endl;
		return '\0';
	}
	return stack[--top];
}

int precedence(char operand) {
	if (operand == '*' || operand == '/' || operand == '%') return 2;
	if (operand == '+' || operand == '-') return 1;
	return 0;
}

bool isempty() {
	return top == 0;
}

int main() {
	cout << "Enter infix string: ";
	string str;
	cin >> str;

	// Step 1: Reverse input and swap '(' with ')'
	reverse(str.begin(), str.end());
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') str[i] = ')';
		else if (str[i] == ')') str[i] = '(';
	}

	string result = "";

	// Step 2: Process like postfix
	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];

		if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
			result += ch;
		}
		else if (ch == '(') {
			push(ch);
		}
		else if (ch == ')') {
			while (!isempty() && stack[top - 1] != '(') {
				result += pop();
			}
			if (!isempty()) pop(); // remove '('
		}
		else {
			while (!isempty() && precedence(ch) < precedence(stack[top - 1])) {
				result += pop();
			}
			push(ch);
		}
	}

	while (!isempty()) {
		result += pop();
	}

	// Step 3: Reverse result to get prefix
	reverse(result.begin(), result.end());

	cout << "Prefix expression: ";
	for (int i = 0; i < result.length(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;

	return 0;
}

