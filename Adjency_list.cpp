#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;


struct Vertex{
	char data;
	Vertex *nextvertex;
	void *startadj;
	
	
}*start=NULL;


struct Adj{
	Vertex *adjvertex;
	Adj *nextadj;
	
};

stack<Vertex*> track;
// const int size=10;
bool visited_arr[10];

void insert_into_adjancy_vertex(char vertex_to_insert){
    Vertex *list=start;
   while(list!=NULL){
       if(list->data==vertex_to_insert){
           cout<<"vertex is found"<<endl;
            // bool flag=false;
// 		while(!flag){
// 	
		string adjacent_vertex;
// 		char adjacent_vertex;
	cout<<"enter adjacent verteces aka edges"<<endl;
		cin>>adjacent_vertex;
		for(int i=0;i<adjacent_vertex.length();i++){
// 		if(adjacent_vertex=='0'){
// 			flag=true;}
				Vertex *temp=start;
				while(temp!=NULL){
				if(temp->data==adjacent_vertex[i]){
					cout<<adjacent_vertex[i]<<" vertex is in list now we can map it "<<endl;
					
					Adj *adjency_vertex=(Adj*)malloc(sizeof(Adj));
					adjency_vertex->adjvertex=temp;
						adjency_vertex->nextadj=NULL;
						
					if(list->startadj==NULL){
						list->startadj=adjency_vertex;
					}else{
					Adj *adj_temp=(Adj*)list->startadj;
					while(adj_temp->nextadj!=NULL){
					adj_temp=adj_temp->nextadj;
					}	
					adj_temp->nextadj=adjency_vertex;
					}
					
				}
			temp=temp->nextvertex;
			}
		    
		}
// 			}}
         
       }
       list=list->nextvertex;
   }
   if(list==NULL){cout<<"this vertex does not exits in list"<<endl;
       return;
   }
  }
	


void insert(){
    // bool flag=false;
    while(true){
	cout<<"enter vertex 0 to terminate"<<endl;
	char vertex;
	cin>>vertex;
	if(vertex=='0'){ break;}
	Vertex *newvertex=(Vertex*)malloc(sizeof(Vertex));
	newvertex->data=vertex;
	newvertex->nextvertex=NULL;
	newvertex->startadj=NULL;
	if(start==NULL){
		start=newvertex;
		}else{
		Vertex *temp=start;
		while(temp->nextvertex!=NULL){
			temp=temp->nextvertex;
			}
		temp->nextvertex=newvertex;}
		
	}
	return;
}

void print(){
	Vertex *temp=start;
	while(temp!=NULL){
		cout<<"vertex: "<<temp->data<<endl;
		cout<<"adgancy list "<<endl;
		if(temp->startadj==NULL){cout<<"null"<<endl;}
		else{Adj *curr=(Adj*)temp->startadj;
		    while(curr!=NULL){
		        cout<<curr->adjvertex->data<<" ";
		        curr=curr->nextadj;
		    }
		    cout<<endl;
		}
		temp=temp->nextvertex;
	}
	
}
bool Is_in_stack(char row){
	int r=(int)row;
	return visited_arr[r];
	
}
bool DFS(Vertex *row,char end){
	track.push(row);
	int r=(int)row->data;
	visited_arr[r]=true;
	if(row->data==end){
		cout<<"path is found"<<endl;
		while(!track.empty()){
		Vertex *top=track.top();
		cout<<top->data;
		track.pop();
		if(!track.empty()){
			cout<<" <-- ";
		}}
		return 1;}
		Adj *col=(Adj*)row->startadj;
	while(col!=NULL){
	if(!Is_in_stack(col->adjvertex->data)){
		if(DFS(col->adjvertex,end)==true){return 1;}
		}
	col=col->nextadj;
	}
	track.pop();
	return 0;	
}

void find_path_undirected(){
	char starting_point;
	char end;
	cout<<"enter starting point"<<endl;
	cin>>starting_point;
	cout<<"enter ending point"<<endl;
	cin>>end;
	Vertex *temp=start;
	while(temp!=NULL){
		if(temp->data==starting_point){
		bool Is_path=DFS(temp,end);
		if(Is_path==false){
		cout<<"no path found from "<<start<<" to "<<end<<endl;
	}
	return;
		}
		temp=temp->nextvertex;
	}

}

int find_degree(char vertex){
	Vertex *temp=start;
	while(temp!=NULL){
		if(temp->data==vertex){
			int degree=0;
			Adj *temp_adj=(Adj*)temp->startadj;
			while(temp_adj!=NULL){
				degree++;
				temp_adj=temp_adj->nextadj;
				}
				
			return degree;
		}
	temp=temp->nextvertex;		
	}
	return 0;
	
	
}
int main(){
     int choice;
	while(choice!=6){
	    cout<<"enter key and 6 to terminate"<<endl;
	    cin>>choice;
	    switch(choice){
	    		case 1:
	insert();
	break;
	case 2:
		print();
		break;
	case 3:
	cout<<"insert edges into vertex .enter vertex number"<<endl;
	char vertex;
	cin>>vertex;
	insert_into_adjancy_vertex(vertex);
	break;
	case 4:
		find_path_undirected();
		break;
	case 5:
		cout<<"enter the vertexto find out degree"<<endl;
		char d_vertex;
		cin>>d_vertex;
	int degree=find_degree(d_vertex);	
	cout<<"degree of vertex "<<d_vertex<<" is "<<degree<<endl;
	        
	    }}
}
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	

