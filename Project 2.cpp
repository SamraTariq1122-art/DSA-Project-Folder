#include<iostream>
#include<conio.h>

using namespace std;
class Book_data{
	public:
		int book_id;
		string name,name2;
		int book_month,book_year;
		Book_data*next;
};
class Singly_link_list{
	public:
		Book_data*head=NULL;
		void insert()
		{
			int r;
			string n,l;
			int m,y;
			cout<<endl<<" Enter Book Id: ";
			cin>>r;
			cout<<endl<<" Enter Book  Name(Don't use space, use '_' instead): ";
			cin>>n;
			cout<<endl<<" Enter Book Writer's Name: ";
			cin>>l;
			cout<<endl<<" Enter  book_month: ";
			cin>>m;
			cout<<endl<<" Enter Book Publish Year: ";
			cin>>y;
			Book_data*new_Book_data=new Book_data;
			new_Book_data->book_id=r;
			new_Book_data->name=n;
			new_Book_data->book_month=m;
			new_Book_data->book_year=y;
			new_Book_data->name2=l;
			new_Book_data->next=NULL;
			if(head==NULL)//         yaha hum daikhaingai kai jo link list ki first Book_data hai wo null hai yani yai pehli Book_data hai j add hwe hai.
			{
				head=new_Book_data;
			}
			else//agar yai pehli Book_data nae hai or baad mai add ho rhi hai to...
			{
				Book_data*last=head;//last Book_data find krni hai link list
				while(last->next!=NULL)
				{
					last=last->next;
				}
				last ->next=new_Book_data;
			}
			cout<<endl<<" New Book '"<<n<<"' by '"<<l<<"' has added Succesfully in the Record! (^_^)"<<endl<<endl;
		}
		void search()//the search will work on the base of id no.
		{
			if(head==NULL)
			{
				cout<<"\n\n  Record list is Empty! (!^!)"<<endl<<endl;
			}
			else{
				int r,found=0;
				cout<<"\n\n Enter Id Number for Book Search: ";
				cin>>r;
				Book_data*searching=head;
				while(searching!=NULL)
				{
					if(r==searching->book_id)
					{
						cout<<"\n\n   Id Number of Book is: "<<searching->book_id<<endl<<endl;
						cout<<"\n\n   Name of the Book is: "<<searching->name<<endl<<endl;
						cout<<"\n\n   Name of the Writer's' is: "<<searching->name2<<endl<<endl;
						cout<<"\n\n   book_month of the Book is: "<<searching->book_month<<endl<<endl;
						cout<<"\n\n   book_year of the Book "<<searching->name<<" Progress is: "<<searching->book_year<<" %"<<endl;
						found++;
					}
					searching=searching->next;
				}
				if(found==0)
				{
					cout<<"\n\n  Search Id "<<r<<" Can't found! (!^!)"<<endl;
				}
			}
		}
		void count_Book_data()
		{
			if(head==NULL)
			{
				cout<<"\n\n                     The Record List Is Empty    (!^!)    "<<endl;
			}
			else{
				int c=0;
				Book_data*count=head;
				while(count!=NULL)
				{
					c++;
					count=count->next;
				}
					cout<<"\n\n    Total Number of Book in the Records are: "<<c<<endl;
			}
		}
		void sort_Book() {  
        //Node current will point to head  
        Book_data*current = head, *index = NULL;  
        int temp;  
          
        if(head == NULL) {  
            return;  
        }  
        else {  
            while(current != NULL) {  
                //Node index will point to node next to current  
                index = current->next;  
                  
                while(index != NULL) {  
                    //If current node's data is greater than index's node data, swap the data between them  
                    if(current->book_id > index->book_id) {  
                        temp = current->book_id;  
                        current->book_id = index->book_id;  
                        index->book_id = temp;  
                    }  
                    index = index->next;  
                }  
                current = current->next;
				cout<<"\n\n The Books Sorting Has been Done Succesfully!"<<endl;  
            }      
        }  
    }
		void update_Book()//the search will work on the base of id no.
		{
			if(head==NULL)
			{
				cout<<"\n\n  Record list is Empty! (!^!)"<<endl<<endl;
			}
			else{
				int r,found=0;
				cout<<"\n\n Enter Id Number for Book to Update  Record: ";
				cin>>r;
				Book_data*searching=head;
				while(searching!=NULL)
				{
					if(r==searching->book_id)
					{
						cout<<endl<<"  Enter NEW Book Id: ";
			            cin>>searching->book_id;
			            cout<<endl<<" Enter New Book Name(Don't use space, use '_' instead): ";
			            cin>>searching->name;
			            cout<<endl<<" Enter New Book Writer's Name: ";
			            cin>>searching->name2;
			            cout<<endl<<" Enter New Book book_month: ";
			            cin>>searching->book_month;
			            cout<<endl<<" Enter Book publish Year: ";
			            cin>>searching->book_year;
			            cout<<endl<<" The Book Record has Updated Succesfully!(^_^)";
						found++;
					}
					searching=searching->next;
				}
				if(found==0)
				{
					cout<<"\n\n  Search Id "<<r<<" Can't found! (!^!)"<<endl;
				}
			}
		}
 			void delete_Book_record()//the search will work on the base of id no.
		{
			if(head==NULL)
			{
				cout<<"\n\n  Record list is Empty! (!^!)"<<endl<<endl;
			}
			else{
				int r,found=0;
				cout<<"\n\n Enter Id Number for Srudent to Delete  Record: ";
				cin>>r;
				if(r==head->book_id)
				{
					Book_data*current=head;
					head=head->next;
					cout<<endl<<" Book Data has Deleted Succesfully!(^_^)";
					found++;
					delete current;
				}
				else{
					Book_data*previous=head;
					Book_data*searching=head->next;
					while(searching!=NULL)
					{
						if(r==searching->book_id)
						{
							previous->next=searching->next;
							cout<<endl<<" Record has been deleted Succesfully!";
							found++;
							delete searching;
							break;
						}
						previous=searching;
						searching=searching->next;
					}	
				}
				if(found==0)
				{
					cout<<endl<<" Search Id Number "<<r<<" Can't found!(!^!)";
				}
		}
	}
	void show_record()
	{
		if(head==NULL)
			{
				cout<<"\n\n  Record list is Empty! (!^!)"<<endl<<endl;
			}
			else{
				Book_data*searching=head;
				while(searching!=NULL)
				{
					
						cout<<"\n\n   Id Number of Book is: "<<searching->book_id<<endl<<endl;
						cout<<"\n\n   Name of the Book is: "<<searching->name<<endl<<endl;
						cout<<"\n\n   Name of the Book Writer is: "<<searching->name2<<endl<<endl;
						cout<<"\n\n   book_month of the Book is: "<<searching->book_month<<endl<<endl;
						cout<<"\n\n   book_year of the Book "<<searching->name<<" is: "<<searching->book_year<<endl;
					searching=searching->next;
				}
				
			}	
	}
	
};
int main()
{
	Singly_link_list L1;
	Label:
		system("cls");
	int choice,password;
	int pass=1234;
	cout<<"     ********************************************"<<endl;
	cout<<"     ********************************************"<<endl;
	cout<<"     ************* Welcome To Login Page ********"<<endl;
	cout<<"\n\n Please Enter Password First To Login: ";
	cin>>password;
	if(password==pass)
	{
	cout<<"                           **********************************"<<endl;
	cout<<"                           *** Book Management For Admin  ***"<<endl;
	cout<<"                           *********************************"<<endl;
	cout<<"   1.Insert Book Record: "<<endl<<endl;
	cout<<"   2.Show_all Book Records: "<<endl<<endl;
	cout<<"   3.Search Book Record: "<<endl<<endl;
	cout<<"   4.Count Book Record: "<<endl<<endl;
	cout<<"   5.Update Book Record: "<<endl<<endl;
	cout<<"   6.Delete Book Record: "<<endl<<endl;
	cout<<"   7.Select To Sort Books In An Asscending Order: "<<endl<<endl;
	cout<<"   8.Exit: "<<endl<<endl;
	cout<<"   Your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			system("cls");
			L1.insert();
			break;
			case 2:
				system("cls");
				L1.show_record();
			break;
			case 3:
				system("cls");
				L1.search();
			break;
			case 4:
				system("cls");
				L1.count_Book_data();
			break;
			case 5:
				system("cls");
				L1.update_Book();
			break;
			case 6:
				system("cls");
				L1.delete_Book_record();
			break;
			case 7:
				system("cls");
				L1.sort_Book();
				break;
			case 8:
				exit(0);
				default: 
				cout<<"\n\n                      Invalid choice!...Please Try again (^-^)"<<endl;		
	}
	getch();
	goto Label;
}
}
