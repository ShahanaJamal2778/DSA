#include<iostream>
#include<stack>
using namespace std;
const int size=6;
bool visited_arr[size];
bool curr_path[size];
stack<int> s;
bool matrix[size][size]={
	
//cyclic directed
	{0,1,0,1,0,0},
	{0,0,1,0,0,0},
	{0,0,0,1,0,0},
	{0,0,0,0,1,1},
	{0,0,0,0,0,0},
	{0,1,0,0,0,0}
};
	
//	directed graph
//	{0,1,0,0},
//	{0,0,1,0},
//	{0,0,0,1}
//	,{1,0,0,0}};
//3 to 0 no path
//{0,1,0,0},
//	{0,0,1,0},
//	{0,0,0,1}
//	,{0,0,0,0}};
	
	
	
//	undirected unconnected
//	{0,1,1,0},
//	{1,0,0,0},
//	{1,0,0,0}
//	,{0,0,0,0}};
	
//cyclic undirected;	
//	{0,1,1,0},
//	{1,0,0,1},
//	{1,0,0,1}
//	,{0,1,1,0}};


void print(){
	for(int i=0;i<size;i++){
	for(int j=0;j<size;j++){
	cout<<matrix[i][j]<<" ";
	}cout<<endl;
}
}
void insert_into_undirected_matrix(){
//	for(int i=0;i<3;i++){
//	for(int j=i+1;j<3;j++){
//	cout<<"intert o or 1 at"<<"row "<<i<<"col "<<j<<endl;
//	cin>>matrix[i][j];
//	matrix[j][i]=matrix[i][j];}}
while(true){
	bool terminate=0;
	cout<<"enter row"<<endl;
	int row ;
	cin>>row;
	cout<<"enter col"<<endl;
	int col ;
	cin>>col;
	matrix[row][col]=1;
	matrix[col][row]=1;
	cout<<"enter 1 to terminate "<<endl;
	cin>>terminate;
	if(terminate==1){
	break;
	}
}
print();
}


void insert_into_directed_matrix(){

while(true){
	bool terminate=0;
	cout<<"enter row"<<endl;
	int row ;
	cin>>row;
	cout<<"enter col"<<endl;
	int col ;
	cin>>col;
	matrix[row][col]=1;
	cout<<"enter 1 to terminate "<<endl;
	cin>>terminate;
	if(terminate==1){
	break;
	}
}
print();
}

bool visited(int row){
		return visited_arr[row]==true;
		}
		
bool curr_stack(int row){
	return curr_path[row]==true;
	
}		
		

bool DFS(int row,int end){
  visited_arr[row] = true;
	if(row==end){
	cout<<"path is found, given path is"<<endl;
	cout<<end<<" <-- ";
	while(!s.empty()){
	int top=s.top();
	 cout<<top;
	 s.pop();
	 if(!s.empty()){cout<<" <-- ";}
	 }
	return 1;
	}
	
		for(int j=0;j<size;j++){
			
		if(matrix[row][j]==1 && !visited(j)){
			s.push(row);
			if(DFS(j,end)){return 1;
			};
			
			}}
			
			if(!s.empty()){
			s.pop();
				if(!s.empty()){
				
//				s.pop();//if there is only one value in stack it will cause unusual behaviour so afterpop recheck
				int top=s.top();
				if(DFS(top,end)){return 1;
				};

				}}
				return 0;
			}
			


void find_path(){
	cout<<"enter starting point aka row"<<endl;
//	char start;
//	cin>>start;
//	char end;
//	cin>>end;
	int start;
	cin>>start;
	cout<<"enter ending point aka row"<<endl;
	int end;
	cin>>end;
	bool path_found_or_not=DFS(start,end);
	if(!path_found_or_not){
		cout<<"no path is found"<<endl;
		
	}
	return;}
	
	
void find_degree(){
	bool und_di;
	cout<<"press 0 for undirected and 1 for directed"<<endl;
	cin>>und_di;
	if(!und_di){
		cout<<"enter the value to find degree of deg(x) "<<endl;
		int row;
		cin>>row;
		int sum_row=0;
		for(int j=0;j<size;j++){
			if(matrix[row][j]==1){
				sum_row++;
			}
		}
		cout<<"degree of undirected graph is: "<<sum_row<<endl;
		return;
	}
	if(und_di){
		cout<<"enter the value to find degree of deg(x) "<<endl;
		int row;
		cin>>row;
		int sum_row=0;
		for(int j=0;j<size;j++){
			if(matrix[row][j]==1){
				sum_row++;
			}}
		cout<<"out degree of directed graph at "<<row<< " is: "<<sum_row<<endl;
		sum_row=0;
		for(int j=0;j<size;j++){
			if(matrix[j][row]==1){
				sum_row++;
			}}
		cout<<"in degree of directed graph at "<<row<< " is: "<<sum_row<<endl;
		return;}
}	
	
bool find_cycle_in_directed_graph(int row){
		 visited_arr[row] = true;
		curr_path[row]=true;
			for(int j=0;j<size;j++){
			if(matrix[row][j]==1){
				cout<<row<<" "<<j<<endl;
				s.push(row);
			if(visited(j) && curr_stack(j) ){
			cout<<"cycle is found"<<endl;
			cout<<"path is found, given path is"<<endl;
			cout<<j<<" <-- ";
			while(!s.empty()){
			int top=s.top();
	 		cout<<top;
	 		s.pop();
	 		if(!s.empty()){cout<<" <-- ";}
					 }	return 1;}
			
			if(!curr_stack(j)){
				find_cycle_in_directed_graph(j);
			}
		}}
		curr_path[row]=false;
		s.pop();
		return 0;
			}
			

bool find_cycle_in_undirected_graph(int row,int parent){
		 visited_arr[row] = true;
	
		for(int j=0;j<size;j++){
			if(matrix[row][j]==1){
					cout<<row<<" "<<j<<endl;
				s.push(row);
			if(visited(j) && j!=parent){
			cout<<"cycle is found"<<endl;
			cout<<"path is found, given path is"<<endl;
			cout<<j<<" <-- ";
			while(!s.empty()){
			int top=s.top();
	 		cout<<top;
	 		s.pop();
	 		if(!s.empty()){cout<<" <-- ";}}
					return 1;}
			
			if(!visited(j)){
				
			find_cycle_in_undirected_graph(j,row);
			s.pop();
			return 0;
			}
		}}
		 
			}			
			



int main(){
//	matrix={{false,true,true,false},
//	{true,false,false,true},
//	{true,false,false,true}
//	,{false,true,1,false}};

	int choice;

	while(true){
	cout<<"enter the key 1 for insert undirected and 2 for insert directed ,3 to findpath,4 for degree,6 for cycle,5 for exit"<<endl;
	cin>>choice;
	switch(choice){
		case 1:
			insert_into_undirected_matrix();
			break;
		case 2:
			insert_into_directed_matrix();
			break;	
		case 3:
			cout<<"find path"<<endl;
			find_path();
			break;
		case 4:
			find_degree();
		break;	
		case 6:
			find_cycle_in_undirected_graph(0,0);
		case 7:
			find_cycle_in_directed_graph(0);
		
			break;

		case 9:
		break;	
	}}
	
	return 0;
}
