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



int main(){
cout<<"enter string"<<endl;
string str;
cin>>str;
for(int i=str.length()-1;i>=0;i--){
	
	if(str[i]>='0' && str[i]<='9'){
		str[i]-=48;
		push(str[i]);
	}else{
		int var1=pop();
		int var2=pop();
//			cout<<var2<<endl;
//				cout<<var1<<endl;
		
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

