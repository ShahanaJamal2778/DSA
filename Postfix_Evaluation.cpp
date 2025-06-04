#include<iostream>
#include<string>
using namespace std;
int stack[10];	
int top=0;
void push(int value){
	if(top==sizeof(stack)/sizeof(stack[0])){
		cout<<"stack overflow"<<endl;
		return;
	}
	stack[top++]=value;
}

int pop(){
	if(top==0){
		cout<<" stack under flow"<<endl;
		return 0;
	}
	top--;
	return stack[top];
}

void print(){
	for(int i=0;i<top;i++){
		cout<<stack[i]<<endl;
		
	}
}

int main(){
cout<<"enter string"<<endl;
string str;
cin>>str;
for(int i=0;i<str.length();i++){
	
	if(str[i]>='1' && str[i]<='9'){
		push(str[i]);
	}else{
		int var2=pop();
		int var1=pop();
		if(str[i]=='*'){
			int res=var1*var2;
			cout<<res<<endl;
			push(res);
		}
		else if(str[i]=='-'){
			int res=var1-var2;
				cout<<res<<endl;
			push(res);
		}
		else if(str[i]=='/'){
			int res=var1/var2;
				cout<<res<<endl;
			push(res);
		}
		else {
			int res=var1+var2;
				cout<<res<<endl;
			push(res);
		}
		
		
		
	}
	
	
}
cout<<"final answer is "<<pop()<<endl;

	
}

