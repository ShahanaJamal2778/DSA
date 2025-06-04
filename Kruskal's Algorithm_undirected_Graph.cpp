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


bool visited_arr[10];
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
    cout<<new_edge->weight<<endl;
        if (count >= 20) {
            cout << "Heap is full!" << endl;
            return;
        }
cout << "Current heap size: " << count << endl;
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
		string adjacent_vertex;
	cout<<"enter adjacent verteces aka edges"<<endl;
		cin>>adjacent_vertex;
		for(int i=0;i<adjacent_vertex.length();i++){
				Vertex *temp=start;
				while(temp!=NULL){
				if(temp->data==adjacent_vertex[i]){
					cout<<adjacent_vertex[i]<<" vertex is in list now we can map it "<<endl;
					cout<<"enter weight for adjacent verteces "<<vertex_to_insert<<" and "<<adjacent_vertex[i]<<endl;
					Adj *adjency_vertex=(Adj*)malloc(sizeof(Adj));
					adjency_vertex->adjvertex=temp;
					int weight;
					cin>>weight;
					adjency_vertex->weight=weight;
					adjency_vertex->nextadj=NULL;
//					
					Edge *new_edge=(Edge*)malloc(sizeof(Edge));
		    			new_edge->weight=weight;
		    			new_edge->from=list;
		    			new_edge->to=temp;
		    			cout<<"enter into heap"<<endl;
		    			push_into_MinHeap(new_edge);
						
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
		    return;
         }
       list=list->nextvertex;
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

int arr_for_cycle_detection[10];


int value_is_in_same_group(int x){
	if(arr_for_cycle_detection[x]==x){
		return arr_for_cycle_detection[x];
	}
	else{
		while(arr_for_cycle_detection[x]!=x){
			int z=arr_for_cycle_detection[x];
			x=arr_for_cycle_detection[z];
		}
		return arr_for_cycle_detection[x];
	}
}
bool DSU(Edge *edge){
//	typecasting into int give ascii of intnot actual int like '1' 49 so
	int a=value_is_in_same_group((((int)edge->from->data)-'0')-1);
	int b=value_is_in_same_group((((int)edge->to->data)-'0')-1);
	if(a!=b){
		for(int i=0;i<10;i++){
cout<<arr_for_cycle_detection[i];	
}
	arr_for_cycle_detection[b]=a;
	for(int i=0;i<10;i++){
	cout<<arr_for_cycle_detection[i];	
}
	return 1;
	}
	else{
//		if a==b   
return 0;}
	}

int sum_of_weights=0;	
	
void Kruskals(){
	while(!Is_MinHeap_empty()){
		    Edge *poped=pop_from_MinHeap();
		    cout<<"popped "<<poped->weight<<endl;
		    if(DSU(poped)){
		    	cout<<poped->from->data<<" and "<<poped->to->data<<" weight is "<<poped->weight<<endl;
		    sum_of_weights+=poped->weight;
				}
				}
			if(Is_MinHeap_empty()){
					cout<<"the cost of Minimum Spanning Tree is "<<sum_of_weights<<endl;
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
	for(int i=0;i<10;i++){
	arr_for_cycle_detection[i]=i;	
}
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
	Kruskals();
	break;

	    }}
}
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	

