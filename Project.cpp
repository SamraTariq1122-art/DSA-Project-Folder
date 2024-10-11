#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <sstream>
#include <unistd.h>
#include <time.h>
using namespace std;

string get_random(int len) {
    string s;
    char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

   	return s;
}

int any_length(){
	int len = 1;
	string s;
    char alphanum[] =
        "1234";

    for (int i = 0; i < len; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    stringstream ambulnc(s);

    int got = 1;
    ambulnc >> got;
    return got;
}

class Clock{
	public:
		int HH=0,MM=0,SS=5,HHc=0,MMc=0,SSc=0;
		int newSS=SS-1,scoreCompleted=0,scoreRequired=5;
		string input_try, get_rand;
		void start(string name){
			system("cls");
			string permission;
			cout<<"\n\t\t\tDo you want to start mission: ";
			cin>>permission;
			cout<<"\n\t\t\t\t Reach The Destination \n";
			cout<<"\n\t\t\t\t HHMMSS";
			cout<<"\n\t\t\t\t "<<HH<<" : "<<MM<<" : "<<SS;
			
		
			while(permission == "yes" && SS > 0|| permission == "YES" && SS > 0 || permission == "Yes" && SS > 0 || permission == "1" && SS > 0 || permission == "" && SS > 0){
				SS--;
				SSc++;
				sleep(2);
				if(SS > 59){
					MM++;
					SS=0;
				}
				if(SSc > 59){
					MMc++;
					SSc = 0;
				}
				if(MM > 59){
					HH++;
					MM = 0 ;
				}
				if(MMc > 59){
					HHc++;
					MMc = 0 ;
				}
				system("cls");
				
				cout<<"\n\t\t  Remaining Time";
				cout<<"\n\t\t HH: MM: SS";
				cout<<"\n\t\t "<<HH<<" : "<<MM<<" : "<<SS;
				cout<<"You must enter: ";
				
	
				if(newSS == SS){
					get_rand = get_random(any_length());
					newSS = SS;
					newSS -= 2;
				}
				cout<<get_rand<<"\n";
				if(_kbhit()){	//  keyboard pressed
					HANDLE standard_input = GetStdHandle(STD_INPUT_HANDLE);
					// read what the user entered
					if (WaitForSingleObject(standard_input, 0) == WAIT_OBJECT_0){
						cout<<"Enter Requried value to drive: ";
						cin>>input_try;
						if(input_try == get_rand){
							scoreCompleted++;
							SS+=2;
						}
					}
					else
    					break;
				}
				
			}
			cout<<"\n\t\tScore Required: "<<scoreRequired;
			cout<<"\n\t\tPlayer Name: "<<name;
			cout<<"\n\t\tScore Completed: "<<scoreCompleted;
			cout<<"\n\t\t Covered Time: ";
			cout<<"\n\t\t "<<HHc<<" : "<<MMc<<" : "<<SSc<<"\n";
			
			
			
			cout<<"\n";
		}
};
	
class Ambulance{
	public:
		string name,address,phno;
		int rank;
		Ambulance *next,*head=NULL;
		
		
		void AmbulanceScr(){
			cout<<
			"\t******** \n"
			"\t*                    *\n"
			"\t*                      * \n"
			"\t*                       *\n"
			"\t*                         *\n"
			"\t*                          *\n"
			"\t*                          *\n"
			"\t*                          *\n"
			"\t**********\n"
			"\t    *             *\n"
			"\t   *  *           *  *\n"
			"\t    *             * \n"
			"\tAmbulance Management System\n\n";
			
		}
		
		void insert(){
			Ambulance *newAmbulance = new Ambulance;
			cout<<"Enter name of new hired: ";
			cin>>newAmbulance->name;
			cout<<"Enter phone number of new hired: ";
			cin>>newAmbulance->phno;
			cout<<"Enter Address of new hired: ";
			cin>>newAmbulance->address;
			cout<<"Enter Rank of new hired: ";
			cin>>newAmbulance->rank;
			newAmbulance->next = NULL;
			
			if(head == NULL){
				head = newAmbulance;
			}else{
				Ambulance *tmp = head;
				while(tmp->next != NULL){
					tmp = tmp->next;
				}
				tmp->next = newAmbulance;
			}
		}
		
		
		
		void deleteNode(string nameOfperon)
		{
      		Ambulance *temp;
			
      		if(head->name == nameOfperon)
      		{
          		temp = head;    
          		head = head->next;
          		delete temp;
          		cout<<"\nEmpolyee Fired.\n";
      		}
      		else
      		{
          		Ambulance *current  = head;
          		while(current->next != NULL)
          		{
             	 	if(current->next->name == nameOfperon)
              		{
                  		temp = current->next;
                  		current->next = current->next->next;
                  		delete temp;
                  		cout<<"\nEmpolyee Fired.\n";
                  		break;
              		}
              		else
                  	current = current->next;
          		}
      		}
      		
		}
		
		Ambulance* searchNode(string nam)
		{
    		Ambulance *temp = head;

    		while(temp != NULL)
    		{
         		if(temp->name == nam){
         			return temp;
				 }
            	 	
         		temp = temp->next;
    		}
    		return NULL;
		}
		
		void display(){
			Ambulance *tmp = head;
			if(tmp != NULL){
				while(tmp != NULL){
					cout<<"Name of Working Employee: "<<tmp->name<<"\n";
					cout<<"Phone Number Working of Empolyee: "<<tmp->phno<<"\n";
					cout<<"Address of Working Employee: "<<tmp->address<<"\n";
					cout<<"Rank of Working Employee: "<<tmp->rank<<"\n";
					tmp = tmp->next;
					cout<<"\n";
				}
			}
			else{
				cout<<"No member found! ";
			}
			cout<<endl;	
		}
};


int main(){
	
	system("Color 74"); // BG color
	Ambulance management;
	Clock timer;
	int option = 0;
	string decision,nameEmpole;
	management.AmbulanceScr();
	
	while(option <= 4){
		cout<<endl;
	
		cout<<"Enter 1 to send to mission\n";
		cout<<"Enter 2 to Admit new Person\n";
		cout<<"Enter 3 to fire worker\n";
		cout<<"Enter 4 to see All currently Working\n";
		cout<<"Enter Option: ";
		cin>>option;
		
		cout<<endl;
		switch(option){
		case 1:
			if(management.head == NULL){
				cout<<"Hire new Member first.\n";
			}else{
				management.display();
				cout<<"Enter Employee Name to send on mission: ";
				cin>>nameEmpole;
				if(nameEmpole == management.searchNode(nameEmpole)->name){
					timer.start(nameEmpole);
					if(timer.scoreCompleted >= timer.scoreRequired){
						cout<<"Do you want to Promote him? ";
						cin>>decision;
						if(decision == "yes" || decision == "Yes" || decision == "1" || decision == "YEs"){
							management.searchNode(nameEmpole)->rank ++;
						}
					}else{
						cout<<"Do you want to fire him? ";
						cin>>decision;
						
						if(decision == "yes" || decision == "Yes" || decision == "1" || decision == "YEs"){
							management.deleteNode(nameEmpole);
						}
					}
				}else{
					cout<<"Name not Found.\n";
				}
			}	
			break;
		case 2:
			management.insert();
			break;
		case 3:
			
			cout<<"Enter name of Employee to Fire.";
			cin>>nameEmpole;
			management.deleteNode(nameEmpole);
			break;
		case 4:
			management.display();
			break;
		default:
			cout<<"Wrong Key Input!\n";
			break;
		}
	}
	

}
