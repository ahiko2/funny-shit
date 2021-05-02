#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int delay()
    {
    for(int i = 0; i<3; i ++)
    {
        cout<<"\n Saving Records ...";
        for(int ii = 0; ii<20000; ii ++)
        {
            for(int iii = 0; iii<20000; iii ++)
            { }
        }
    }
    
    cout<<"\n Exiting Now ...";
    for(int i = 0; i<3; i ++){
    for(int ii = 0; ii<20000; ii ++) { 
        for(int iii = 0; iii<20000; iii ++){
        }
        } 
    }

    return 0;
}

int checkListOfStudentsRegistered()
    {
    cout<<"\n - Check List of Student Registered by Username-- ";	

    //check if record already exist..
    ifstream read;
    read.open("db.dat");

    if(read)
    {   int recordFound =0; 
        string line;
        while(getline(read, line)) {
            char name[100];
            strcpy(name, line.c_str());
            char onlyname[100];
            strncpy(onlyname, name, (strlen(name) - 4));
            cout<<" \n " << onlyname;
        }
        read.close();        
    }
    else
    {
     cout<<"\n No Record found :(";
    }
	
	
    cout<<"\n Please any key to continue..";
    getchar(); getchar();
return 0;
}
int registerStudent()
{
    cout<<"\n ----- Form to Register Student ---- \n";	

    string name, username, password;
    
    cout<<"\n Enter Name : ";     cin>>name;
    cout<<"\n Enter Username : ";     cin>>username;
    cout<<"\n Enter password : ";     cin>>password;
    
    
    //check if record already exist..
    ifstream read;
    read.open("db.dat");
    
    if(read)
    {   int recordFound =0; 
	   string line;
	    while(getline(read, line)) {
    	if(line == username+".dat" )
    	{
    		recordFound = 1 ;
    	    break;
		}
        }
        if(recordFound == 1)
        {
    	cout<<"\n Username already Register. Please choose another username ";
    	getchar(); getchar();
    	delay();
    	read.close();
    	return 0;
		}
	}
    read.close();

    ofstream out;
	out.open("db.dat", ios::app);
	out<<username+".dat"<<"\n";
	out.close();

	ofstream out1;
	string temp = username+".dat";
	out1.open(temp.c_str());
	out1<<name<<"\n"; 	out1<<username<<"\n"; 	out1<<password<<"\n";
	
	out1.close();

	cout<<"\n Student Registered Successfully !!";
    
    cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;		
}
int adminView()
{	
    int goBack = 0;
    while(1)
    {
        system("cls");
        cout<<"\n 1 Register a Student";
        cout<<"\n 4 Check List of Student registered by userame";
        cout<<"\n 0. Go Back <- \n";
        int choice;

        cout<<"\n Enter you choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: registerStudent();break;  
            case 4: checkListOfStudentsRegistered(); break;
            case 0: goBack = 1;break;
            default: cout<<"\n Invalid choice. Enter again ";
            getchar();           	
        }   

        if(goBack == 1)
        {
        break; //break the loop
        }     

    }

    return 0;
}
int adminLogin()
{
system("cls");
cout<<"\n --------- Admin Login --------";	

string username;
string password;

cout<<"\n Enter username : ";
cin>>username;
cout<<"\n Enter password : ";
cin>>password;

if(username=="admin" && password=="admin@2") 
{
    adminView();
    getchar();	
    delay();
}   
else
{
cout<<"\n Error ! Invalid Credintials..";	
cout<<"\n Press any key for main menu ";
getchar();getchar();
}

return 0;
}
int main(int argc, char** argv) {
	
while(1)
{
	system("cls");
	cout<<"\n Attendance Management System \n";
	cout<<"-------------------------------------\n\n";
	
	cout<<"1. Student Login\n";
	cout<<"2. Admin Login\n";
	
	cout<<"0. Exit\n";
	int choice;
	
	cout<<"\n Enter you choice: ";
	cin>>choice;
	
	switch(choice)
	{
	
	case 2: adminLogin(); break;
	case 0: 
	        while(1)
	        {
		    system("cls");
        	cout<<"\n Are you sure, you want to exit? y | n \n";
        	char ex;
        	cin>>ex;
        	if(ex == 'y' || ex == 'Y')
        	   exit(0);
        	else if(ex == 'n' || ex == 'N')
             {
             	 break;
             }
             else{
             	cout<<"\n Invalid choice !!!";
             	getchar();
             }

     	   }
            break;
             	 
    default: cout<<"\n Invalid choice. Enter again ";
    getchar();
	}   		        

}
	
return 0;
}    
