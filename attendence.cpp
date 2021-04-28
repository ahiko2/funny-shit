
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <curses.h>
//including header file
#include "gg.h"

using namespace std;
int main(){
    welcome();
}
void welcome(){

    while(1){
        system("clear"); //clear screen first
        cout<<"Attendance Management System"<<endl;
        cout<<"----------------------------"<<endl<<endl;

        cout<<"1.Admin Login";
        cout<<"\n2.Student Login";
        cout<<"\n0.Exit";
        int choice;
        cout<<"\nEnter Your choice :"; cin>>choice;
        switch (choice) {
            case 1: adminLogin();
                break;
            case 2: studentLogin();
                break;
            case 0: while(1){
                    system("clear");
                    char key;
                    cout<<"Wanna exit?  y|n :"; cin>>key;
                    if(key=='y' || key=='Y'){
                        exit(0);
                    }
                    else if(key=='n' || key=='N'){
                        break;
                    }
                    else{
                        cout<<"invalid choice";
                        getchar();
                    }
                }
                break;
            default: cout<<"invalid Choice"<<endl;


        }

    }

}
int adminLogin(){

    system("clear");
    cout<<"Admin login \n";
    string username; 
    cout<<"Enter username:"; cin>>username;
    string password; 
    cout<<"Enter password:"; cin>>password;
    if(username=="admin" && password=="admin"){
        adminView();
        
    }
    else{
        cout<<"Invalid input\nPress anyway key top continue...\n";
        getchar();getchar(); 
    }



    return 0;

}
int adminView(){
    
    int goback=0;
    while(1){

        system("clear");
        cout<<"\n 1 Register a Student";
        cout<<"\n 4 Check List of Student registered by userame";
        cout<<"\n 0. Go Back <- \n";
        cout<<"Enter your choice :";
        int choice; cin>>choice;
        switch (choice)
        {
            case 1: registerStudent();   break;

           // case 3:deleteStudentbyRollno();   break; 

            case 4:checkListOfStudentsRegistered();   break;

           // case 5:checkPresenseCountbyRollno();  break;

           // case 6:getListOfStudentsWithTheirPresenseCount();   break;
            
            case 0: goback = 1; break;

            default: cout<<"invalid choice, Enter again";  break;

            getchar();
        }
        if(goback==1){
            break;
        }


    }

    return 0;

}
int registerStudent(){

    cout<<"Student Register Form";
    string name,username,password,rolln;

    cout<<"Student Name :"; cin>>name;
    cout<<"Create Roll Number :"; cin>>rolln;
    cout<<"Create username :"; cin>>username;

    

    cout<<"Create password :"; cin>>password;
    getchar();
    //check where username is already exist
    ifstream read;
    //first create database file
    read.open("db.dat");

    if(read)
    {   int recordFound =0; 
	   string line;
	    while(getline(read, line)) 
		{
			if(line == username+".dat" )
			{
				recordFound = 1 ;
				break;
			}
        }
        if(recordFound == 1)
        {
			cout<<"\n Username already Register. Please choose another username";
            cout<<"Redo again from beginning";
			getchar(); getchar();
			
			read.close();
			return 0;
		}
	}
    read.close();
    
    //create file name in db.dat
    ofstream out;
    out.open("db.dat",ios::app);
    out<<username+".dat"<<endl;
    out.close();

    ofstream out1;
    //create file and input student data here
    string temp=username+".dat";
    out1.open(temp.c_str());
    out1<<name<<endl;
    out1<<rolln<<endl;
    out1<<username<<endl;
    out1<<password<<endl;
    out1.close();

    cout<<"\n Student Registered Successfully !!";
    
    cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;	
}
int checkListOfStudentsRegistered(){
    cout<<"Checking stuents list by student username\n";
    
    //check if already exist
    ifstream read;
    read.open("db.dat");
    if(read){
        int recordfound=0;
        string line;
        while(getline(read,line)){
            char name[100];
            strcpy(name,line.c_str());

            char onlyname[100];
            strncpy(onlyname,name,(strlen(name)-4));
            cout<<"\n"<<onlyname;
        }
        
        read.close();
    }
    
    else cout<<"nope\n";
	
	
    cout<<"\n Please any key to continue..";
    getchar(); getchar();
    return 0;
}



int studentLogin(){

    return 0;

}
