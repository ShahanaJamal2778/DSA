#include<iostream>
using namespace std;
	const int size=11;
	int hashtable[size];

void insert(int key){
	int ind=key%size;
	int ind2=8-(key%8);
	int ind3=key%size;
	
	
int i=0;
//while(hashtable[(ind3+(ind2*i))%11]!=-1){
while(hashtable[ind]!=-1){

	i++;
	ind=(ind3+(ind2*i))%11;
		
if(i==size){
	cout<<"table is full"<<endl;
	return ;
}	

}
	
	hashtable[ind]=key;
	return;
	

}


void print(){
	for(int i=0;i<size;i++){
		cout<<hashtable[i]<<endl;
	}
	
	   
}

void search(){
		cout<<"ente the number to insert and zero to exit"<<endl;
int value;
cin>>value;
		for(int i=0;i<size;i++){
			if(value==hashtable[i]){
			
		cout<<hashtable[i]<<" value is found"<<endl;
		return;}
	}
	
}

int main(){
for(int i=0;i<size;i++){
	hashtable[i]=-1;
}

int choice;
while(choice!=0){

cout<<"enter the key 0 to exit"<<endl;
cin>>choice;
switch(choice){
	case 1:
		{
		while(true){
	cout<<"ente the number to insert and zero to exit"<<endl;
int value;
cin>>value;
	if(value==0){
		break;
	}else{
	
	insert(value);}
}
	break;}
	case 2:
		print();
		break;
	case 3:
	search();
	break;

	}
	
	}

	
	
}

