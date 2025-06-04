#include<iostream>
#include<cstdlib>
using namespace std;

struct students{
	string SeatNo;
	students *SNext;
};
struct courses{
	int CNo;
	courses *CNext;
	students *stulist;
	
}*start=NULL;


void Add_course(){
	courses *ptr=(courses*)malloc(sizeof(courses));
	cout<<"Enter course no"<<endl;
	cin>>ptr->CNo;
	ptr->CNext=NULL;
	if(start==NULL){
		start=ptr;
		
	}
	else{
	courses *temp=start;
	while(temp->CNext!=NULL){
		temp=temp->CNext;	
	}
	temp->CNext=ptr;
	}
	}
	
	
void delete_course(){

		int todel;
		cout<<"enter the course no to delete"<<endl;
		cin>>todel;
		if(start->CNo==todel){
			courses *temp=start;
			
			start=start->CNext;
			free(temp);
			return;}
			else{
				courses *prev=start;
				courses  *curr=start->CNext;
			while(curr!=NULL){
				if(curr->CNo==todel){
					prev->CNext=curr->CNext;
					free(curr);
					return;
				}
				curr=curr->CNext;	
				prev=prev->CNext;
				
				}
				}
				
				
				
				}
				
				
void search_course(){
	if(start==NULL){
		cout<<"list is empty"<<endl;
	}
	int search;
	cout<<"enter the course number to be searched"<<endl;
	cin>>search;
		courses *temp=start;
		while(temp!=NULL){
			if(temp->CNo==search){
			cout<<"course is found"<<endl;
			return;
			}
		else{
			temp=temp->CNext;}	
		}
		cout<<"course is not found"<<endl;
			
		}
		
void print_courses(){

		courses *temp=start;
		cout<<"courses list"<<endl;
		while(temp!=NULL){
		
			cout<<"course NO "<<temp->CNo<<endl;
			temp=temp->CNext;
		}
		}	
		
		
void add_student(){
		int search;
	cout<<"enter the course number to add student"<<endl;
	cin>>search;
		courses *temp=start;
		while(temp!=NULL){
			if(temp->CNo==search){
			cout<<"course is found"<<endl;
			cout<<"enter student seat number to add in this course"<<endl;	
		string seatnumber;
		cin>>seatnumber;
		students *ptr=(students*)malloc(sizeof(students));
		ptr->SeatNo=seatnumber;
		ptr->SNext=NULL;
		if(temp->stulist==NULL){
			temp->stulist=ptr;
			return;		
				
		}
		else{
	students *s_temp=temp->stulist;
	while(s_temp->SNext!=NULL){
		s_temp=s_temp->SNext;	
	}
	s_temp->SNext=ptr;
	return;
		}
	}
			
	else{
			temp=temp->CNext;
			}	
		}
	
		cout<<"course is not found"<<endl;
	}			


void delete_student(){
		int search;
	cout<<"enter the course number to delete student "<<endl;
	cin>>search;
		courses *temp=start;
		while(temp!=NULL){
			if(temp->CNo==search){
			cout<<"course is found"<<endl;
			cout<<"enter student seat number of student in this course to be deleted"<<endl;	
		string todel;
		cin>>todel;
		if(temp->stulist->SeatNo==todel){
			students *s_temp=temp->stulist;
			temp->stulist=temp->stulist->SNext;
			free(s_temp);
			return;
			}
			else{
				students *prev=temp->stulist;
				students  *curr=temp->stulist->SNext;
			while(curr!=NULL){
				if(curr->SeatNo==todel){
					prev->SNext=curr->SNext;
					free(curr);
					return;
				}
				curr=curr->SNext;	
				prev=prev->SNext;
				
				}
				}
				return;
				}
	else{
			temp=temp->CNext;
			}	
		
		}
		cout<<"course is not found"<<endl;
	}			


void delete_student_from_dataframe(){
		cout<<"enter student seat number of student in this course to be deleted"<<endl;	
		string todel;
		cin>>todel;
	courses *temp=start;
		while(temp!=NULL){
		
		if(temp->stulist->SeatNo==todel){
			students *s_temp=temp->stulist;
			temp->stulist=temp->stulist->SNext;
			free(s_temp);
			}
			else{
				students *prev=temp->stulist;
				students  *curr=temp->stulist->SNext;
			while(curr!=NULL){
				if(curr->SeatNo==todel){
					prev->SNext=curr->SNext;
					free(curr);
				}else{
				
				curr=curr->SNext;	
				prev=prev->SNext;
			}
				}
				}
	
			temp=temp->CNext;}	
		
		
	cout<<"student having seat number "<<todel<<" has been removed from this dataframe"<<endl;
	
	
}


void list_of_students_Of_a_course(){
	cout<<"enter the course number to view students list enrolled in this course"<<endl;
	int course_no;
	cin>>course_no;
	courses *temp=start;
	while(temp!=NULL){
		if(temp->CNo==course_no){
			
			cout<<"course is found"<<endl;
			students *s_temp=temp->stulist;
			if(temp->stulist==NULL){
				cout<<"No student has been enrolled in this course"<<endl;
				return;
			}else{
			
			cout<<"the list of students enrolled in "<<course_no<<" is"<<endl;
			while(s_temp!=NULL){
				cout<<"seat number: "<<s_temp->SeatNo<<endl;
				s_temp=s_temp->SNext;
				}
				return;
			}
				}else{
			temp=temp->CNext;
		}
		
		
	}
	cout<<"course is not found"<<endl;
	
	
	
}

void search_a_student_in_a_course(){
		int search;
	cout<<"enter the course number to search student in thiis course "<<endl;
	cin>>search;
		courses *temp=start;
		while(temp!=NULL){
			if(temp->CNo==search){
			cout<<"course is found"<<endl;
			cout<<"enter student seat number of student in this course to be search in this course "<<endl;
		string search_st;
		cin>>search_st;
		if(temp->stulist==NULL){
				cout<<"No student hasbeen enrolled in this course"<<endl;
				return;
		}
		else if(temp->stulist->SeatNo==search_st){
			cout<<"this student is enrolled in this course"<<endl;
			return;
	}
			else{
				students *curr=temp->stulist;
				
			while(curr!=NULL){
				if(curr->SeatNo==search_st){
				cout<<"this student is enrolled in this course"<<endl;
				return;
				}
				else{
				
				curr=curr->SNext;	
			
			}
				}
					cout<<search_st<<"student is not enrolled in this course"<<endl;
					return;
				
				
				}
			}
	else{
			temp=temp->CNext;
			}	
		}

cout<<"course is not found"<<endl;

	
	
	
}


void list_of_courses_of_student(){
	cout<<"enter student seat number of student in this course to be search in dataframe"<<endl;
		string search_st;
		cin>>search_st;
		courses *temp=start;
		int c=0;
			while(temp!=NULL){
		if(temp->stulist->SeatNo==search_st){
		    	c=1;
			
			cout<<"this student is enrolled in course "<<temp->CNo<<endl;
		
		
	}
			else{
				students  *curr=temp->stulist;
			while(curr!=NULL){
				if(curr->SeatNo==search_st){
				c=1;
			cout<<"this student is enrolled in course "<<temp->CNo<<endl;
			return;
			
				}
				else{
				
				curr=curr->SNext;	
			
			}
				}
				
				}
			temp=temp->CNext;
			}
		if(c==0){
			cout<<search_st<<" student is not found in the data"<<endl;
		
			
		}
}
	
	
	
	



int main(){
	int choice;
	while(choice!=11){
	
	cout<<"enter key and 11 to exit"<<endl;
	
	cin>>choice;
	switch(choice){
		case 1:
			Add_course();
			break;
		case 2:
			delete_course();
			break;
		case 3:
			search_course();
			break;
		case 4:
			print_courses();
			break;
		case 5:
			add_student();
			break;
		case 6:
			delete_student();
			break;
		case 7:
			delete_student_from_dataframe();
			break;
		case 8:
			list_of_students_Of_a_course();
			break;
		case 9:
			search_a_student_in_a_course();
			break;
		case 10:
			list_of_courses_of_student();
			break;
		case 11:
			break;
						
								}
								}
	
	
	
}
