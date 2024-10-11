#include <iostream>
#include<stdlib.h>
using namespace std;

struct customer_Info{
	customer_Info *pre,*next;
	string cust_name,cust_cnic;
	int cust_age,cust_account_no;
};
struct cust_Money{
	cust_Money *pre,*next;
	int cust_account_no,cust_account_balance;
};

struct Employee { 
	string nameE,PhoneE,AdressE,cnicE,ageE;
	int BalanceE; 
	Employee* left;
	Employee* right;
};


Employee* GetNewNode(string nameE,string PhoneE,string AdressE,string cnicE,string ageE,int BalanceE) {
	Employee* newNode = new Employee();
	newNode->nameE = nameE;
	newNode->AdressE = AdressE;
	newNode->cnicE = cnicE;
	newNode->ageE = ageE;
	newNode->BalanceE = BalanceE;
	newNode->left = newNode->right = NULL;
	return newNode;
}


Employee* Insert(Employee* root) {

	string nameE,PhoneE,AdressE,cnicE,ageE;
	int BalanceE;
	cout<<"Enter Employee Name: ";
	cin>>nameE;
	cout<<"Enter Empoyee Designation: ";
	cin>>AdressE;
	cout<<"Enter Employee CNIC: ";
	cin>>cnicE;
	cout<<"Enter Employee AGe: ";
	cin>>ageE;
	cout<<"Enter Employee Balance: ";
	cin>>BalanceE;
	if(root == NULL) {
		root = GetNewNode(nameE,PhoneE,AdressE,cnicE,ageE, BalanceE);
	}

	else if(BalanceE <= root->BalanceE) {
		root->left = Insert(root->left);
	}

	else {
		root->right = Insert(root->right);
	}
	return root;
}

void display(Employee* root)
{
	if(root != NULL)
	{
		display(root->left);
		cout<<"Employee Name: "<<root->nameE<<" \n";
		cout<<"Employee CNIC: "<<root->cnicE<<"\n";
		cout<<"Employee Address: "<<root->AdressE<<"\n";
		cout<<"Employee Balance: "<<root->BalanceE<<"\n";
		cout<<"Employee Age: "<<root->ageE<<"\n";
		display(root->right);
	}
	cout<<endl;
}

class Stack{
	public:
		int n=100, top=-1,cust_age[100],cust_account_no[100],cust_account_balance[100];
		string cust_name[100],cust_cnic[100];
		
		void insert(){
			system("CLS");
	
   			if(top>=n-1)
   				cout<<"Stack Overflow"<<endl;
   			else {
   				    cout<<"             --------------------\n";
   					cout<<"             |New Account form  |\n";
   					cout<<"             --------------------\n\n";
      			top++;
      			cout<<"Enter Customer's name: ";
      			cin>>cust_name[top];
      			cout<<"Enter Customer's age: ";
      			cin>>cust_age[top];
      			cout<<"Enter Customer's CNIC: ";
      			cin>>cust_cnic[top];
      			cout<<"Enter Customer's Account Number: ";
      			cin>>cust_account_no[top];
      			cout<<"Enter Customer's Balance: ";
      			cin>>cust_account_balance[top];
      			
   			}
   			system("CLS");
   			cout<<"Record Saved sucessfully !\n";
		}
		void remove() {
   			if(top<=-1)
   				cout<<"Stack Underflow"<<endl;
   			else {
      			cout<<"The removed element name: "<< cust_name[top] <<endl;
      			cout<<"The removed element CNIC: "<<cust_cnic[top]<<endl;
      			top--;
   			}
		}
		void display() {
			
   			if(top>=0) {
      			cout<<"Stack elements\n";
      		for(int i=top; i>=0; i--){
      			cout<<"Customer' Name: "<<cust_name[i]<<"\n";
      			cout<<"Customer's Age: "<<cust_age[i]<<"\n";
      			cout<<"Customer's Account Number: "<<cust_account_no[i]<<"\n";
      			cout<<"Customer's CNIC: "<<cust_cnic[i]<<"\n";
      			cout<<"Customer's Account Balance: "<<cust_account_balance[i]<<"\n";
      		    cout<<"----------------------------";
			  }
      			cout<<endl;
   			} else
   				cout<<"Stack is empty\n";
		}
};

class customer_user
{
	public:
		customer_Info *head,*tail;
		cust_Money *head1,*tail1;
		int account_number;
		Stack stackitems;
	customer_user()
	{
		head = NULL;
		tail = NULL;
		head1 = NULL;
		tail1 = NULL;
	}


	void Create_Account(string cust_name,string cust_cnic,int cust_age,int cust_account_no,int cust_account_balance)
	{
		

		customer_Info *temp=new customer_Info;
		temp->pre = NULL;
		temp->cust_name = cust_name;
		temp->cust_cnic = cust_cnic;
		temp->cust_age = cust_age;
		temp->cust_account_no = cust_account_no;
		temp->next = NULL ;
		if(head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			customer_Info *currentNode = new customer_Info;
			currentNode = tail;

			currentNode->next = temp;
			temp->pre = currentNode;
			temp->next= head;
			tail = temp;
		}
		


					
		cust_Money *temp1=new cust_Money;
		temp1->pre = NULL;
		
		temp1->cust_account_no = cust_account_no;
		temp1->cust_account_balance = cust_account_balance;
		temp1->next = NULL ;
		if(head1 == NULL)
		{
			head1 = temp1;
			tail1 = temp1;
		}
		else
		{
			cust_Money *currentNode = new cust_Money;
			currentNode = tail1;

			currentNode->next = temp1;
			temp1->pre = currentNode;
			temp1->next= head1;
			tail1 = temp1;	
		}
	
	}
	void Login_Customer()
	{
		cout<<"\n          Login_Customer"	<<endl;
		string v,d,w,user_value;
		cout<<"Press 'V' to view money available in your account."<<endl;
		cout<<"\nPress 'D' to deposit money  in your account."<<endl;
		cout<<"\nPress 'W' to wethdraw morom from your account."<<endl;
		cout<<"\nEnter the value : ";
		cin>>user_value;     
		
		if(user_value == "v")
		{
			cust_Money *temp = new cust_Money;
			temp = tail1;
			while (temp->pre != tail1)
			{	
				if(temp->cust_account_no == account_number)
				{
					cout<<"\nYour Balance is "<<temp->cust_account_balance<<endl;
					Login_Customer();
					break;
				}
				
				temp = temp -> pre;
			}
		}
		
		else if(user_value == "d")
		{
			int deposit_money;
			cout<<"\nEnter your Deposit Money  ";
			cin>>deposit_money;
			cust_Money *temp = new cust_Money;
			temp = tail1;
			while (temp->pre != tail1)
			{	
				if(temp->cust_account_no == account_number)
				{
					
					temp->cust_account_balance = temp->cust_account_balance + deposit_money; 
					cout<<"\nYour Account Number : "<<temp->cust_account_no<<endl;
					cout<<"\nYour Balance is "<<temp->cust_account_balance<<endl;
					Login_Customer();
					break;
				}
				
				temp = temp -> pre;
			}
			
		}
		

		else if(user_value == "w") 
		{
			int deposit_money;
			cout<<"\nEnter your Deposit Money  ";
			cin>>deposit_money;
			cust_Money *temp = new cust_Money;
			temp = tail1;
			while (temp->pre != tail1)
			{	
				if(temp->cust_account_no == account_number)
				{
					
					temp->cust_account_balance = temp->cust_account_balance - deposit_money; 
					cout<<"\nYour Account Number : "<<temp->cust_account_no<<endl;
					cout<<"\nYour Balance is "<<temp->cust_account_balance<<endl;
					Login_Customer();
					break;
				}
				
				temp = temp -> pre;
			}
		
		}
		else
		{
			cout<<"------Wrong------"<<endl;
		}
	}
	
	void Login_Admin()
	{
		int password = 1234;
		int User_Password;
		cout<<"                --------------------\n";
   		cout<<"                |Admin Login Panel  |\n";
   		cout<<"                --------------------\n\n";
		cout<<"\nEnter your password for Login_Admin : ";
		cin>>User_Password;
		
		if(User_Password == password)
		{
			
			string l,d,user_value;
			cout<<"\nPress 'L' to view list of all account holders and their money in bank\nPress 'R' to remove any account from the system"<<endl;
			cout<<"\nEnter the value : ";
			cin>>user_value;
			if(user_value == "l")
			{
				customer_Info *temp = new customer_Info;
				temp = tail;
				system("CLS");
				cout<<"-----------List Values-------------\n";
				stackitems.display();
				while (temp->pre != tail)
				{	
					cout<<"Name : "<<temp->cust_name<<endl;
					cout<<"CNIC : "<<temp->cust_cnic<<endl;
					cout<<"Age : "<<temp->cust_age<<endl;
					cout<<"Account Number : "<<temp->cust_account_no<<endl;
					cout<<"--------------------------"<<endl;
					temp = temp -> pre;
				}
			
			}
			
			else if(user_value == "r")
			
			{	
				cout<<"\nEnter the Delete account Number : ";
				int Value;
				cin>>Value;
				if(head->cust_account_no==Value)
				{
					customer_Info *firstnode = new customer_Info;
					firstnode = head -> next;
					firstnode -> pre = NULL;
					head -> next = NULL;
					head = firstnode;
					
					customer_Info *temp = new customer_Info;
					temp = tail;
					cout<<"-----------List Values-------------\n";
					while (temp->pre != tail)
					{	
						cout<<"Name : "<<temp->cust_name<<endl;
						cout<<"CNIC : "<<temp->cust_cnic<<endl;
						cout<<"Age : "<<temp->cust_age<<endl;
						cout<<"Account Number : "<<temp->cust_account_no<<endl;
						cout<<"--------------------------"<<endl;
						temp = temp -> pre;
					}
					
				}
				
				else if(tail->cust_account_no==Value)
				{
					customer_Info*DLT = new customer_Info;
					DLT=tail->pre ;
					DLT->next = NULL;
					tail->pre = NULL;
					tail=DLT;
					
					customer_Info *temp = new customer_Info;
					temp = tail;
					cout<<"-----------List Values-------------\n";
					while (temp->pre != tail)
					{	
						cout<<"Name : "<<temp->cust_name<<endl;
						cout<<"CNIC : "<<temp->cust_cnic<<endl;
						cout<<"Age : "<<temp->cust_age<<endl;
						cout<<"Account Number : "<<temp->cust_account_no<<endl;
						cout<<"--------------------------"<<endl;
						temp = temp -> pre;
					}
				}
				else 
				{	
					customer_Info *temp = new customer_Info;
					temp = tail;
					cout<<"-----------List Values-------------\n";
					while (temp->pre != tail)
					{	
						if(temp->cust_account_no==Value)
						{
							customer_Info *deletion=new customer_Info;
							customer_Info *nextNode=new customer_Info;
							customer_Info *previousNode=new customer_Info;
							customer_Info *temp=new customer_Info;
							temp=head;
							while (temp->next!=head)
							{
								if (temp->cust_account_no==Value)
								{
									deletion=temp;
								}
								temp=temp->next;
							}
							nextNode=deletion->next;
							previousNode=deletion->pre;
								
							nextNode->pre=deletion->pre;
							previousNode->next=deletion->next;
							
							deletion->next=NULL;
							deletion->pre=NULL;
							
							customer_Info* tempa = new customer_Info;
							tempa = tail;
							cout<<"-----------List Values-------------\n";
							while (tempa->pre != tail)
							{	
								cout<<"Name : "<<tempa->cust_name<<endl;
								cout<<"CNIC : "<<tempa->cust_cnic<<endl;
								cout<<"Age : "<<tempa->cust_age<<endl;
								cout<<"Account Number : "<<tempa->cust_account_no<<endl;
								cout<<"--------------------------"<<endl;
								tempa = tempa -> pre;
							}
							
						}

						temp = temp -> pre;
						
					}
//	
					
					
				}
			}
		
		}
		else
		{
			cout<<"--------Your password is incorrect------------";
		}	
	}
	
		
	int options()
	{
		string user_value,a,b,c;
		Employee *myEmployees = NULL;
		while(user_value == "a" || user_value == "b" || user_value == "c" || user_value == "d" || user_value == ""){
			cout<<"\n------------------------------------------------------------------------------------------------------------------------\n"<<endl;
			cout<<"                                BANKING MANAGEMENT SYSTEM BY : \n"<<endl;
			cout<<"                                   -> Hussnain Sarwar(111) "<<endl;
			cout<<"                                   -> Muhammad Yasin(154) "<<endl;
			cout<<"                                   -> Shah Jahan(109) "<<endl;
			cout<<"\n------------------------------------------------------------------------------------------------------------------------\n"<<endl;
			system("pause");
			cout<<"\n Choose option 'A' to create new bank account\n"<<endl;
			cout<<"\n Choose option 'B' to login as customer\n"<<endl;
			cout<<"\n Choose option 'C' to Login as Admin\n"<<endl;
			cout<<"\n Choose option 'D' to See Employee details\n"<<endl;
			cout<<" Enter the value : ";
			cin>>user_value;
			system("CLS");
		
			if(user_value == "a" )
			{
				stackitems.insert();
			
			}
			else if(user_value == "b" )
			{
				Create_Account("UZAIR", "7878", 19, 109, 411);
				Create_Account("ALI", "2341", 22, 3499, 7458);
				Create_Account("ZAID", "31104", 22, 154, 7469);
		       cout<<"             -------------------------\n";
   			   cout<<"             |Customers Accounts info  |\n";
   			   cout<<"             --------------------------\n\n";
				cout<<"\nEnter Your Account_No To Search Data: ";
				cin>>account_number;
				customer_Info *temp = new customer_Info;
				temp = tail;
				while (temp->pre != tail)
				{	
					if(temp->cust_account_no == account_number)
					{	
						Login_Customer();
						return account_number;
				
						break ;
					}
				temp = temp -> pre;
				}
			
			}
			
			else if(user_value == "c" )
			{
						
				Create_Account("Zain", "78787", 19, 7895, 0);
				Create_Account("Hammad", "54255", 12, 8594, 0);
				Create_Account("Shah Jahan", "84255", 18, 109, 0);
				Create_Account("Yasin", "74145", 12, 154, 0);
				Create_Account("Hussnain", "32255", 32, 111, 0);
				Login_Admin();
			}
			else if (user_value == "d"){
				int valu;
		cout<<"             --------------------\n";
   		cout<<"             |Employee database  |\n";
   		cout<<"             --------------------\n\n";
				cout<<"\nEnter 1 for add new Employee ";
				cout<<"\nEnter 2 for display Employee List";
				cout<<"\nEnter the value: ";
				cin>>valu;
				if(valu == 1){
					myEmployees = Insert(myEmployees);
				}else if(valu == 2){
					display(myEmployees);
				}
				
			}
			else
			{
				cout<<"Your option  is incorrect"<<endl;
			}
		}
	}	
};

int main()
{	
	customer_user Z;
	
	Z.options();

	return 0;
}
