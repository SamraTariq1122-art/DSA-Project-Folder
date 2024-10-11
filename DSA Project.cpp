#include<iostream>
#include<conio.h>
#include <time.h>
#include <sstream>
#include <unistd.h> 
using namespace std;

struct User{
	string message;               
	string gender;
	User *next;
	string name ;
	string subject;
	string password ;
	string type;
	bool quiz;	
	string roll_no;
	int marks;
};
struct Material{
	string mat_quest,mat_ans,subj,quest_num;
	Material *next;
};

Material *mathead = NULL;
int total_quiz_quest = 0;

void insert_Quiz(string sbject,string quest_num,string type){
	system("cls");
	cout<<"\n\n\n\t\t                Quiz Selection    ";
	cout<<"\n\t\t__________________";
	cout<<"\n\t\t| Make New"<<type;
	
	Material *newmat = new Material;
	if(type == "Quiz" || type == "Assignment"){
		cout<<"\n\t\tEnter Question "<<quest_num<<": ";
	}else{
		cout<<"\n\t\tEnter Notification "<<quest_num<<": ";
	}
	cin>>newmat->mat_quest;
	if(type == "Quiz" || type == "Assignment"){
		cout<<"\n\t\tEnter Answer: ";
	}else{
		cout<<"\n\t\tEnter Notification details: ";
	}
	cin>>newmat->mat_ans;
	newmat->subj = sbject;
	newmat->quest_num = quest_num;
	newmat->next = NULL;
			
	if(mathead == NULL){
		mathead = newmat;
	}else{
		Material *tmp = mathead;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = newmat;
	}
}

void display_Material(string typ){
	Material *tmp = mathead;
	cout<<"\n\t\t-------Pending "<<typ<<" Attempt--------\n";
	while(tmp != NULL){
		
		cout<<"\n\t\t"<<tmp->quest_num<<". "<<tmp->mat_quest<<endl;
		if(typ == "Message"){
			cout<<"\n\t\t Notification details: "<<tmp->mat_ans<<endl;
		}
		tmp = tmp->next;
	}
	if(mathead == NULL){
		cout<<"\n\n\n\t\t\tNo "<<typ<<" Avaiable";
	}
	cout<<endl;
}


User *userhead = NULL;

void insert(string type){
	system("cls");
	cout<<"\n\n\n\t\t__________________";
	cout<<"\n\t\t|>>>>>>-"<<type<<"'s Registration -<<<<<<";
	cout<<"\n\t\t|";
	cout<<endl;
	User *newUser = new User;
	cout<<"\n\tEnter name of new "<<type<<": ";
	cin>>newUser->name;
	cout<<"\n\tEnter Gender of new "<<type<<": ";
    cin>>newUser->gender;
    
	if(type == "teacher" || type == "Teacher"){
		cout<<"\n\tEnter Teaching Subject of new "<<type<<": ";
	}else if(type == "student" || type == "Student"){
		cout<<"\n\tEnter Studying Subject of new "<<type<<": ";
	}
	
	cin>>newUser->subject;
	newUser->type = type;
	string passw = "";
			
	cout<<"\n\tEnter Password for new "<<type<<": ";
	cin>>newUser->password;
	cout<<"\n\tRe-Enter Password for new "<<type<<": ";
	cin>>passw;
	while(passw != newUser->password){
		system("cls");
		cout<<"\n\tEnter Password for new "<<type<<": ";
		cin>>newUser->password;
		cout<<"\n\tRe-Enter Password for new "<<type<<": ";
		cin>>passw;
		if(newUser->password == passw){
			cout<<"\n\tUser Registered.\n";
		}else{
			cout<<"\n\tEnter Password Again";
		}
			sleep(2);
	}
			
	newUser->next = NULL;
			
	if(userhead == NULL){
		userhead = newUser;
	}else{
		User *tmp = userhead;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = newUser;
	}
}

User* searchNode(string keyN,string keyP)
{
    User *temp = userhead;

    while(temp != NULL)
    {
         if(temp->name == keyN && temp->password == keyP){
         	cout<<"FOund";
         	return temp;
		 }
             
         temp = temp->next;
    }
    return userhead;
}

void decideUser(string type);
void UserLoggedin(User* successLogin,string usernameU,string subject);

void add_material(User* successLog,string material_type){
	int tryOp;
	if(material_type == "Quiz" || material_type == "Assignment"){
		cout<<"\n\n\t\t Enter 1 to add Question: ";
	}else{
		cout<<"\n\n\t\t Enter 1 to add Accouncement: ";
	}
	
	cout<<"\n\n\t\t Enter 2 to go Back";
	cout<<"\n\n\t\t Enter Option: ";
	cin>>tryOp;
	if(tryOp == 1){
		if(material_type == "Quiz" || material_type == "Assignment"){
			int total_quiz_quest;
			cout<<"\n\t Enter Total Questions to add: ";
			cin>>total_quiz_quest;
				
			for(int i=1;i<=total_quiz_quest;i++){
				stringstream ss;
				ss << i;
				string str = ss.str();
				insert_Quiz(successLog->subject,str,material_type);
			}
		}else if (material_type == "Message"){
			insert_Quiz(successLog->subject,"1","Message");
		}
		
		sleep(1);
		UserLoggedin(successLog,successLog->name,successLog->subject);	
	}else if(tryOp == 2){
		UserLoggedin(successLog,successLog->name,successLog->subject);
	}else{
		cout<<"Wrong key Entered...";
		sleep(2);
		UserLoggedin(successLog,successLog->name,successLog->subject);
	}
}

void UserLoggedin(User* successLogin,string usernameU,string subject){
	system("cls");
	cout<<"\n\n\n\t\t__________________";
	cout<<"\n\t\t|>>>>>>- "<<successLogin->type<<"'s Dashboard -<<<<<<";
	cout<<"\n\t\t|";
	cout<<"\n\t\t| Username: "<<successLogin->name;
	cout<<"\n\t\t| Subject:"<<successLogin->subject<<"           Status: Online";
	cout<<endl;
	string optionT;
	cout<<"\n\t\t| q) Quiz";
	cout<<"\n\t\t| a) Add Assignment";
	cout<<"\n\t\t| m) Add Message Announcement";
	cout<<"\n\t\t| l) Log out";
	cout<<"\n\t\t| Select --> ";
	cin>>optionT;
	if(successLogin->type == "Teacher"){
		if(optionT == "q"){
			add_material(successLogin,"Quiz");
				
		}else if(optionT == "a"){
			add_material(successLogin,"Assignment");
		}else if(optionT == "m"){
			add_material(successLogin,"Message");
		}else if(optionT == "l"){
			decideUser(successLogin->type);
		}else {
			cout<<"\n\t\t Press any key to continue...";
			if(_kbhit()){
				UserLoggedin(successLogin,usernameU,subject);
			}
		}
	}else if (successLogin->type == "Student"){
		if(optionT == "q"){
			display_Material("Quiz");
		}else if(optionT == "a"){
			display_Material("Assignment");
		}else if(optionT == "m"){
			display_Material("Message");
		}else if(optionT == "l"){
			decideUser(successLogin->type);
		}else {
			cout<<"\n\t\t Press any key to continue...";
			if(_kbhit()){
				UserLoggedin(successLogin,usernameU,subject);
			}
		}
		
	}
}
void homePage();

void decideUser(string type){
	system("cls");
	cout<<"\n\n\n\t\t                "<<type<<" Dashboard    ";
	cout<<"\n\t\t__________________";
	cout<<"\n\t\t|Enter 1 to Register New";
	cout<<"\n\t\t|Enter 2 to Login";
	cout<<"\n\t\t|Enter 3 to back";
	int decide = 0;
	cout<<"\nEnter option: ";
	cin>>decide;
	cout<<endl;
	
	if(decide == 1){
		
		insert(type);
		decideUser(type);
	}else if(decide == 2){
		
		string userN ,userP ;
		cout<<"\n\tEnter "<<type<<" User Name: ";
		cin>>userN;
		cout<<"\n\tEnter "<<type<<" Password: ";
		cin>>userP;
		User *foundd = searchNode(userN,userP);
		string Uname = foundd->name;
		string Upass = foundd->password;
		if(userN == Uname && userP == Upass){
			
			UserLoggedin(foundd,Uname,Upass);
		
		}else {
		
			cout<<"\nUser name or Password is wrong..";
			sleep(2);
			decideUser(type);
			
		}
		
		
		
	}else if(decide == 3){
		
		homePage();
		
	}
	
}




void homePage(){
	system("cls");
	cout<<"\n\n\n\t\t______________";
	cout<<"\n\t\t|>>>>>>- Welcome To LMS -<<<<<<";
	cout<<"\n\t\t|";
	cout<<"\n\t\t|Supeior University:";
	cout<<"\n\t\t|-Enter ur Login type:              ";
	cout<<endl;
	
	User person;
	int optionHome;
	cout<<"\n\tEnter 1 for teacher login\n";
	cout<<"\tEnter 2 for student login\n";
	cout<<"\tEnter your option: ";
	cin>>optionHome;
	
	system("cls");
	if(optionHome == 1){
		decideUser("Teacher");
	}else if(optionHome == 2){
		decideUser("Student");
	}else{
		cout<<"Wrong key pressed";
	}
	
	
}


int main(){
	homePage();
	
}
