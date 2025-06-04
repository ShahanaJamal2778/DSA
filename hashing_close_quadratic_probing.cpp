#include<iostream>
using namespace std;
	const int size=10;
	int hashtable[size];

void insert(int key){
	int ind=key%size;
//	for(int i=0;i<size;i++){
//		if(hashtable[ind]==-1){
//			hashtable[ind]=key;
//			return;	
//		}
//		ind=ind+(i*i);
//		i++;
//	
//	}
int i=0;
//while(hashtable[(ind+i*i)%size]!=-1){
while(hashtable[ind]!=-1){

	i++;
		ind=(i*i+ind)%size;
if(i==size){
	cout<<"table is full"<<endl;
	return ;
}	
//	ind=(ind*ind+1)%size;
}
	//hashtable[(ind+i*i)%size]=key;
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
//insert(78);
//insert(45);
//insert(53);
//insert(118);
//insert(218);
//insert(78);
//insert(45);
//insert(53);
//insert(118);
//insert(218);
//print();
	
	
}

