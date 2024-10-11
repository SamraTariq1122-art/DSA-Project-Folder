#include<iostream>
#include<conio.h>
using namespace std;

struct node
{
	int id;
	char name[50];
	char qua[30];
	char addrs[50];
	char city[50];
	char jobtitle[30];
	int salary;
	char date[30];
	node  *prev,*next;
	
};
class employ
{
	private:
		node  *head;
		char ch;
	public:
			employ()
			{
				head=NULL;
				
			}
	void menu()
	{
	
		cout<<"1-  Add a record:      "<<endl;
		cout<<"2-  Search a record:   "<<endl;
		cout<<"3-  Update a record:   "<<endl;
		cout<<"4-  Delete a record:   "<<endl;
		cout<<"5-  Displlay a record: "<<endl;
		cout<<"6-  Exit              "<<endl;
		return ;
		
	}
	void add_first()
	{
		node *newer=new node;
		
		cout<<" n\t\t Enter the employ id:";
		cin>>newer->id;
		fflush(stdin);
		cout<<"\n\t\t Enter the full name of employ:";
		cin.getline(newer->name,50);
		fflush(stdin);
		cout<<"\n\t\t Enter the qalification of employ:";
		cin.getline(newer->qua,30);
		fflush(stdin);
		cout<<"\n\t\t Enter the address :";
		cin.getline(newer->addrs,50);
		fflush(stdin);
		cout<<"\n\t\t Enter the city :";
		cin.getline(newer->city,30);
		fflush(stdin);
		cout<<"\n\t\t Enter the job title :";
		cin.getline(newer->jobtitle,30);
		fflush(stdin);
		cout<<"\n\t\t Enter the salary :";
		cin>>newer->salary;
		fflush(stdin);
		cout<<"\n\t\t Enter the start date :";
		cin.getline(newer->date,30);
		fflush(stdin);
		newer->next=head;
		newer->prev=NULL;
		if(head!=NULL)
		{
			head->prev=newer;
		}
		head=newer;
		cout<<"\n\t\t Record Inserted Successfuly:"<<endl;
		
		
    }
    void add_last()
    {
	   
	   if(head==NULL)
       {
	   
       
		cout<<"\n\t\t Link is empty:"<<endl;
		cout<<"\n\t\t Add a new record\n\tpree Y  or  N:";
		cin>>ch;
		if(ch=='Y' ||ch=='Y')
		{
			add_first();
			return;
			
		}
		else
		{
			exit(1);
		}
	   }
       else
       {
       	node *temp=head;
       	while(temp->next!=NULL)
       	{
       		temp=temp->next;
	    }
       	node *newer=new node;
		fflush(stdin);
		cout<<"\n\t\t Enter the employ id:";
		cin>>newer->id;
		fflush(stdin);
		cout<<"\n\t\t Enter the full name of employ:";
		cin.getline(newer->name,50);
		fflush(stdin);
		cout<<"\n\t\t Enter the qalification of employ:";
		cin.getline(newer->qua,30);
		fflush(stdin);
		cout<<"\n\t\t Enter the address :";
		cin.getline(newer->addrs,50);
		fflush(stdin);
		cout<<"\n\t\t Enter the city :";
		cin.getline(newer->city,30);
		fflush(stdin);
		cout<<"\n\t\t Enter the job title :";
		cin.getline(newer->jobtitle,30);
		fflush(stdin);
		cout<<"\n\t\t Enter the salary :";
		cin>>newer->salary;
		fflush(stdin);
		cout<<"\n\t\t Enter the start date :";
		cin.getline(newer->date,30);
		fflush(stdin);
		newer->next=NULL;
		temp->next=newer;
		newer->prev=temp; 
		
		
		}
}
		void add_after()
		
		{
		   
		 if(head==NULL)
    {
	   
       
		cout<<"\n\t\t Link is empty:"<<endl;
		cout<<"\n\t\t Add a new record\n\tpree Y  or  N:";
		cin>>ch;
		if(ch=='Y' ||ch=='Y')
		{
			add_first();
			return;
			
		}
		else
		{
			exit(1);
		}     
		      
	}
	else	
		{
			int val;
			cout<<"\n\t\t Enter the id after which you want to add a new record:";
			cin>>val;
			bool flag=false;
			node *temp=head;
			node*p;
			while(temp!=NULL)
			{
		if(temp->id==val)
		{
		node *newer=new node;
		fflush(stdin);
		cout<<"\n\t\t Enter the employ id:";
		cin>>newer->id;
		fflush(stdin);
		cout<<"\n\t\t Enter the full name of employ:";
		cin.getline(newer->name,50);
		fflush(stdin);
		cout<<"\n\t\t Enter the qalification of employ:";
		cin.getline(newer->qua,30);
		fflush(stdin);
		cout<<"\n\t\t Enter the address :";
		cin.getline(newer->addrs,50);
		fflush(stdin);
		cout<<"\n\t\t Enter the city :";
		cin.getline(newer->city,30);
		fflush(stdin);
		cout<<"\n\t\t Enter the job title :";
		cin.getline(newer->jobtitle,30);
		fflush(stdin);
		cout<<"\n\t\t Enter the salary :";
		cin>>newer->salary;
		fflush(stdin);
		cout<<"\n\t\t Enter the start date :";
		cin.getline(newer->date,30);
		fflush(stdin);
		if(temp->next!=NULL)
		{
			newer->next=temp->next;
			newer->prev=temp;
			p=temp->next;
			p->prev=newer;
			temp->next=newer;
			
		}			
		else			
	{
		newer->next=temp->next;
		newer->prev=temp;
		temp->next=newer;
	}			
	flag=true;
	}
	temp=temp->next;
	}
	if(flag==false)
	
	{
		cout<<"\n\t\t Id is not found"<<endl;
	}		
  }
}
		
		
    void add_before()
	{
		
		if(head==NULL)
    {
	   
       
		cout<<"\n\t\t Link is empty:"<<endl;
		cout<<"\n\t\t Add a new record\n\tpree Y  or  N:";
		cin>>ch;
		if(ch=='Y' ||ch=='Y')
		{
			add_first();
			return;
			
		}
		else
		{
			exit(1);
		}     
		      
	}
	else	
		{
			int val;
			cout<<"\n\t\t Enter the id after which you want to add a new record:";
			cin>>val;
			bool flag=false;
			node *temp=head;
			node*p;
			while(temp!=NULL)
			{
		if(temp->id==val)
		{
		node *newer=new node;
		fflush(stdin);
		cout<<"\n\t\t Enter the employ id:";
		cin>>newer->id;
		fflush(stdin);
		cout<<"\n\t\t Enter the full name of employ:";
		cin.getline(newer->name,50);
		fflush(stdin);
		cout<<"\n\t\t Enter the qalification of employ:";
		cin.getline(newer->qua,30);
		fflush(stdin);
		cout<<"\n\t\t Enter the address :";
		cin.getline(newer->addrs,50);
		fflush(stdin);
		cout<<"\n\t\t Enter the city :";
		cin.getline(newer->city,30);
		fflush(stdin);
		cout<<"\n\t\t Enter the job title :";
		cin.getline(newer->jobtitle,30);
		fflush(stdin);
		cout<<"\n\t\t Enter the salary :";
		cin>>newer->salary;
		fflush(stdin);
		cout<<"\n\t\t Enter the start date :";
		cin.getline(newer->date,30);
		fflush(stdin);
		if(temp->next!=NULL)
		{
			newer->next=temp->next;
			newer->prev=temp;
			p=temp->next;
			p->prev=newer;
			temp->next=newer;
			
		}			
		else			
	{
		newer->next=temp->next;
		newer->prev=temp;
		temp->next=newer;
	}			
	flag=true;
	}
	temp=temp->next;
	}
	if(flag==false)
	
	{
		cout<<"\n\t\t Id is not found"<<endl;
	}		
  }
}		
	void del()
	{
		
		node *temp = head; 
	if(head==NULL)
    {
	   
       
		cout<<"\n\t\t link is empty:"<<endl;
		cout<<"\n\t\t add a new record\n\tpree Y  or  N:";
		cin>>ch;
		if(ch=='Y' ||ch=='Y')
		{
			add_first();
			return;
			
		}
		else
		{
			exit(1);
		}     
		      
	}
	else	
		{
			int val;
			cout<<"\n\t\t Enter the id after which you want to add a new record:";
			cin>>val;
			bool flag=false;
			if(temp->id == val)
			{
				
				
				head=temp->next;
				head->prev=NULL;
				flag=true;
				delete temp;
				if(flag==true)
				{
					cout<<"Record has been successfully:";
				}
				
			}
			else
			{
				while(temp!=NULL)
				{
					if(temp->id==val)
					{
						node *p,*q;
						if(temp->next==NULL)
						{
						p=temp->prev;
						p->next=NULL;
						flag=true;
						delete temp;	
						}
						else
						{
							p=temp->prev;
							q=temp->next;
							p->next=q;
							q->prev=p;
							flag=true;
							delete temp;
							
						
						}	
					}
					
				temp=temp->next;	
				}
				if(flag==false)
				{
					cout<<"\n\t\t\t Value is not found:"<<endl;
				}
			}
	}
			
			
}
			
		
		void show()
		{
			if (head==NULL)
			{
				cout<<"\n\t\tList is Empty: "<<endl;
				cout<<"\n\t\tAdd a new Record\n\tPree Y or N : ";
				cin>>ch;
				if(ch=='Y'|| ch=='y')
				{
					add_first();
					return;
				}
				else
				{
					exit(1);
				}
			}
			else
			{
			 node *temp =head;
			 while(temp!=NULL)
			 {
			 	cout<<"\n\t\t Information of Employee"<<endl;
			 	cout<<"\n\t\t ID: "<<temp->id<<endl;
			 	cout<<"\n\t\t Name:"<<temp->name<<endl;
			 	cout<<"\n\t\t Qualification :"<<temp->qua<<endl;
			 	cout<<"\n\t\t City :"<<temp->city<<endl;
			 	cout<<"\n\t\t Job Title :"<<temp->jobtitle<<endl;
		 		cout<<"\n\t\t Salary :"<<temp->salary<<endl;
	     		cout<<"\n\t\t Starting Date :"<<temp->date<<endl;
	     		
	     		temp=temp->next;
			 }	
		    }
			
		}
		
		void search()
		{
			if(head==NULL)
			{
				cout<<"\n\t\tList is Empty :"<<endl;
				cout<<"\n\t\tAdd a new Record\n\tPree Y or N :";
				cin>>ch;
				if(ch== 'Y'||ch=='y')
				{
					add_first();
					return;
				}
				else
				{
					int val;
					cout<<"\n\t\t Enter Employee ID which you want to search:";
					cin>>val;
					node *temp=head;
					bool flage=false;
					if(temp->id==val)
                     {
                     	cout<<"\n\t\t Information of Employee"<<endl;
			        	cout<<"\n\t\t ID: "<<temp->id<<endl;
			        	cout<<"\n\t\t Name:"<<temp->name<<endl;
			 	        cout<<"\n\t\t Qualification :"<<temp->qua<<endl;
		        	 	cout<<"\n\t\t City :"<<temp->city<<endl;
		        	 	cout<<"\n\t\t Job Title :"<<temp->jobtitle<<endl;
		        		cout<<"\n\t\t Salary :"<<temp->salary<<endl;
	            		cout<<"\n\t\t Starting Date :"<<temp->date<<endl;
	     		        return;
	     	            	
					 }
					 temp=temp->next;
				}
			}
		}
		void update()
		{
			if(head==NULL)
			{
				cout<<"\n\t\tList is Empty:"<<endl;
				cout<<"\n\t\t Add a new Record\n\t Press Y or N:";
				cin>>ch;
				if(ch=='Y'||ch=='y')
				{
					add_first();
					return;
				}
				else
				{
				  exit(1);	
				}
			}
			else
			{   
			    node *newer =  new node;
				int val;
				cout<<"\n\t\t Enter Employee ID where you want to Update:";
				cin>>val;
				node *temp=head;
				while(temp!=NULL)
				{
					if(temp->id==val)
					{
						fflush(stdin);
		                cout<<"\n\t\t Enter the employ id:";
	                	cin>>newer->id;
	                	fflush(stdin);
	                	cout<<"\n\t\t Enter the full name of employ:";
	                	cin.getline(newer->name,50);
	                	fflush(stdin);
	                	cout<<"\n\t\t Enter the qalification of employ:";
	                	cin.getline(newer->qua,30);
	                	fflush(stdin);
	                	cout<<"\n\t\t Enter the address :";
	                	cin.getline(newer->addrs,50);
		                fflush(stdin);
		                cout<<"\n\t\t Enter the city :";
                		cin.getline(newer->city,30);
                  		fflush(stdin);
	                	cout<<"\n\t\t Enter the job title :";
		                cin.getline(newer->jobtitle,30);
	                	fflush(stdin);
	                 	cout<<"\n\t\t Enter the salary :";
		                cin>>newer->salary;
	                 	fflush(stdin);
		                cout<<"\n\t\t Enter the start date :";
		                cin.getline(newer->date,30);
	                	fflush(stdin);
					}
					temp=temp->next;
				}
				cout<<"\n\t\t Record has been Updated Sucessfully";
			}
		}
	 };

int main()
{
	int n;
	char ch;
	employ em;
	cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"                                         WELCOME TO THE EMPLOY SYSTEM                                        "<<endl;
	cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
	x2:
	em.menu();
	
	cout<<"\n\t\tEnter your Choice :";
	cin>>n;
	if(n==1)
	{
		x1:
		cout<<"\n\t\t Where you want to add Record:"<<endl;
		cout<<"\n\t\t 1- very first record:"<<endl;
		cout<<"\n\t\t 2- very last record: "<<endl;
		cout<<"\n\t\t 3- your location add record to after record:"<<endl;
		cout<<"\n\t\t 4- add before record :"<<endl;
		cin>>n;
		if(n==1)
		{
			em.add_after();
			cout<<"\n\t\t Do you want to go main menu :"<<endl;
			cin>>ch;
			fflush(stdin);
			if(ch=='Y'||ch=='y')
			{
				goto x2;
			}
			else
			{
				exit(1);
				
			}
		}
		else if(n==2)
		{
			em.add_last();
			cout<<"\n\t\t Do you want to go main menu:"<<endl;
			cin>>ch;
			
			
			if(ch=='Y'||ch=='y')
			{
				goto x2;
				
			}
			else
			{
				exit(1);
				
			}
		}
		
		else if(n==3)
		{
			em.add_after();
			cout<<"\n\t\t Do you want to go main menu :"<<endl;
			cin>>ch;
			if(ch=='Y'||ch=='y')
			{
				goto x2;
			}
			else
			{
				exit(1);
			}
		}
		else if(n==4)
		{
			em.add_before();
			cout<<"\n\t\t Do you want to go main menu:"<<endl;
			cin>>ch;
			if(ch=='y'||ch=='Y')
			{
				goto x2;
			}
			else
			{
				exit (1);
			}
		}
		else
		{
			cout<<"\n\t\t Choose Correct Answer:"<<endl;
			goto x1;
		}
	}
	else if(n==2)
	{
		em.search();
		cout<<"\n\t\t Do you want to go main menu :"<<endl;
		cin>>ch;
		if (ch=='Y'||ch=='y')
		{
			goto x2;
		}
		else
		{
			exit(1);
		}
	}
	else if (n==3)
	{
	    em.update();
	    cout<<"\n\t\t Do you want to go main menu :"<<endl;
		cin>>ch;
		if (ch=='Y'||ch=='y')
		{
			goto x2;
		}
		else
		{
			exit(1);
		}
    }
    else if(n==4)
    {
    	em.del();
    	cout<<"\n\t\t Do you want to go main menu :"<<endl;
		cin>>ch;
		if (ch=='Y'||ch=='y')
		{
			goto x2;
		}
		else
		{
			exit(1);
		}
	}
	else if(n==5)
	{
		em.show();
		cout<<"\n\t\t Do you want to go main menu :"<<endl;
		cin>>ch;
		if (ch=='Y'||ch=='y')
		{
			goto x2;
		}
		else
		{
			exit(1);
		}
	}
	else if(n==6)
	{
		exit(1);
	}
	else 
	{
		cout<<"\n\t\t choose correct answer :"<<endl;
		goto x2;
	}
	return 0;
}






















