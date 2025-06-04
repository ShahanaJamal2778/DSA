#include<iostream>
#include<cstdlib>

using namespace std;


struct Vertex{
	char data;
	Vertex *nextvertex;
	void *startadj;
	
	
	
}*start=NULL;


struct Adj{
	Vertex *adjvertex;
	Adj *nextadj;
	int weight;
};

struct Edge{
	int weight;
	Vertex *to;
	Vertex *from;
};


// const int size=10;
bool visited_arr[10];
int sum_of_weights=0;
Edge *HeapNode[20];


bool Is_visited(char row){
	int r=(int)row;
	return visited_arr[r];
	
}

int count = 0;

bool Is_MinHeap_empty(){
	return (count==0)? 1:0;
}

void swap(Edge *arr[], int n1, int n2) {
    Edge *t = arr[n1];
    arr[n1] = arr[n2];
    arr[n2] = t;
}

int find_weight(Edge *edge){
	return edge->weight;
	
}
void up_heapify(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (find_weight(HeapNode[parent]) > find_weight(HeapNode[index])) {
            swap(HeapNode, parent, index);
            index = parent;
        } else {
            break;
        }
    }
}

void push_into_MinHeap(Edge *new_edge){
    
        if (count >= 20) {
            cout << "Heap is full!" << endl;
            return;
        }

        HeapNode[count]=new_edge;
        up_heapify(count);
        count++;
    
	
	
}

void down_heapify() {
    int i = 0;

    while (true) {
        int l_child = 2 * i + 1;
        int r_child = 2 * i + 2;
        int smallest = i;

        if (l_child < count && find_weight(HeapNode[l_child]) < find_weight(HeapNode[smallest]))
            smallest = l_child;

        if (r_child < count && find_weight(HeapNode[r_child]) < find_weight(HeapNode[smallest]))
            smallest = r_child;

        if (smallest != i) {
            swap(HeapNode, i, smallest);  // Fix: use index, not values
            i = smallest;
        } else {
            break;
        }
    }
}

Edge* pop_from_MinHeap() {
    if (count == 0) {
        cout << "Heap is empty!" << endl;
        return 0;
    }
    Edge *temp=HeapNode[0];
	swap(HeapNode, 0, count - 1);  
    count--;                  // Shrink heap
    down_heapify();  
	return temp;      // Restore heap property
}




void insert_into_adjancy_list_of_vertex(char vertex_to_insert){
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
					cout<<"enter weight for adjacent verteces "<<vertex_to_insert<<" and "<<adjacent_vertex[i]<<endl;
					int ad_weight;
					cin>>ad_weight;
					Adj *adjency_vertex=(Adj*)malloc(sizeof(Adj));
					adjency_vertex->adjvertex=temp;
					adjency_vertex->weight=ad_weight;
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
	


void insert_vertex(){
    // bool flag=false;
    while(true){
	cout<<"enter 0 to terminate"<<endl;
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


void Primse(Vertex *row){
	int r=(int)row->data;
	visited_arr[r]=true;
		cout<<"vertex: "<<row->data<<endl;
		cout<<"adgancy list "<<endl;
//		insert edges into min heap
		if(row->startadj==NULL){cout<<"disconnected vertex"<<endl;}
		else{
		Adj *col=(Adj*)row->startadj;
		    while(col!=NULL){
		    if(!Is_visited(col->adjvertex->data)){
		    	cout<<col->adjvertex->data<<"("<<col->weight<<")  ";
		    	Edge *new_edge=(Edge*)malloc(sizeof(Edge));
		    	new_edge->weight=col->weight;
		    	new_edge->from=row;
		    	new_edge->to=col->adjvertex;
		    	push_into_MinHeap(new_edge);
		    	}
		        col=col->nextadj;
		   	} cout<<endl;
		}
		    while(!Is_MinHeap_empty()){
		    Edge *poped=pop_from_MinHeap();
		    if(!Is_visited(poped->to->data)){
		    	int r=(int)poped->to->data;
				visited_arr[r]=true;
				 cout<<poped->weight<<" weight is added into "<<sum_of_weights<<endl;
				sum_of_weights+=poped->weight;
		cout<<"vertex: "<<poped->to->data<<endl;
		cout<<"adgancy list "<<endl;
		if(poped->to->startadj==NULL){cout<<"disconnected vertex"<<endl;}
		else{
		Adj *col=(Adj*)poped->to->startadj;
		
		    while(col!=NULL){
		    if(!Is_visited(col->adjvertex->data)){
		    	cout<<col->adjvertex->data<<"("<<col->weight<<")  ";
		    	Edge *new_edge=(Edge*)malloc(sizeof(Edge));
		    	new_edge->weight=col->weight;
		    	new_edge->from=poped->to;
		    	new_edge->to=col->adjvertex;
		    	push_into_MinHeap(new_edge);
		    	}
		        col=col->nextadj;
		    	}
		    	cout<<endl;
		    	}
				}
				}
			if(Is_MinHeap_empty()){
					cout<<"the cost of Minimum Spanning Tree is "<<sum_of_weights<<endl;
				return;
			}
		
	}

	






void call_Primse(char vertex_to_start){
	cout<<"call primse"<<endl;
		Vertex *list=start;
   while(list!=NULL){
       if(list->data==vertex_to_start){
           cout<<"starting vertex has been found"<<endl;
        	Primse(list);
			return;
        	}
        	else{
        		list=list->nextvertex;
			}
		}
   if(list==NULL){cout<<"this vertex does not exist in list"<<endl;
       return;
   }
}



void print(){
	Vertex *temp=start;
	while(temp!=NULL){
		cout<<"vertex: "<<temp->data<<endl;
		cout<<"adgancy list "<<endl;
		if(temp->startadj==NULL){cout<<"null"<<endl;}
		else{Adj *curr=(Adj*)temp->startadj;
		    while(curr!=NULL){
		    	
		        cout<<curr->adjvertex->data<<" ("<<curr->weight<<") ";
		        curr=curr->nextadj;
		    }
		    cout<<endl;
		}
		temp=temp->nextvertex;
	}
	
}



int main(){
     int choice;
	while(choice!=6){
	    cout<<"enter key and 6 to terminate"<<endl;
	    cin>>choice;
	    switch(choice){
	case 1:
	insert_vertex();
	break;
	case 3:
		print();
		break;
	case 2:
	cout<<"insert edges into vertex .enter vertex number"<<endl;
	char vertex;
	cin>>vertex;
	insert_into_adjancy_list_of_vertex(vertex);
	break;
	case 4:
		cout<<"insert starting point "<<endl;
		char c;
		cin>>c;
		call_Primse(c);
	break;

	    }}
}
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	

	    	
	    	
	    	
	    	
	    	
	    	

