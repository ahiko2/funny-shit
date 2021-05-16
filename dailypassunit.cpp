#include<iostream>
#include <vector>
#include <fstream>
using namespace std;
class dailypass{

    //node declare
    struct applicant{
        string name,occu;
        int icNo,contactNO;
        applicant *next;
    };
    string reason=" ";
private:
    applicant* start,* end;
public:
    dailypass(){
        start=NULL;
        end=NULL;
    }
    int menu(){
        int option;
        cout << "[1] Register Pass\n[2] Display Pass\n[3] Update Pass\n[4] Count Pass\n[5] Exit\n\n";
        cin>>option;
        return option;
    }
    void newPass();
    void registerpass(applicant*);
    void displaypass();
    void updatepass();
    void countpass();



};
void dailypass::newPass() {
    applicant *n=new applicant();
    n->next=NULL;
    int option;
    cout<<"Name      :"; cin>>ws;getline(cin,n->name);
    cout<<"Occuption :"; cin>>n->occu;
    cout<<"Ic Number :"; cin>>n->icNo;
    cout<<"Contact Number :"; cin>>n->contactNO;
    registerpass(n);

}
void dailypass::registerpass(applicant *n) {
    //create newnode and connect
    if(start==NULL){
        start=n;
        end=n;
    }
    else{
        end->next=n;
        end=n;
        end->next=NULL;
    }

}
void dailypass::displaypass() {
    applicant *n=start;
    int option,icNo,flag=0;
    cout << "Display Pass " << endl;
    cout << "[1] Individual " << endl;
    cout << "[2] All Records " << endl;
    cin>>option;
    if(option==1){
        cout<<"Enter IC number to display:"; cin>>icNo;

        while(n->icNo==icNo){
            n=n->next;
        }
        if(n->icNo=icNo){
            cout<<"Name :"<<n->name<<endl;
            cout<<"Occuption:"<<n->occu<<endl;
            cout<<"Ic Number:"<<n->icNo<<endl;
            cout<<"Contact Number:"<<n->contactNO<<endl;
            flag=1;
        }
        if(flag==0){
            cout<<"cannot found"<<endl;
        }
    }
    else if(option==2){
        while(n!=NULL){
            cout<<"Name :"<<n->name<<endl;
            cout<<"Occuption:"<<n->occu<<endl;
            cout<<"Ic Number:"<<n->icNo<<endl;
            cout<<"Contact Number:"<<n->contactNO<<endl;
            n=n->next;
        }
    }

}
void dailypass::updatepass() {
    int icNo,flag=0,option;
    cout<<"Enter Passport number to update"<<endl;
    cin>>icNo;

    applicant *n=start;
    //search until found
    while (n->icNo!=icNo){
        n=n->next;
    }
    //when found
    if(n->icNo==icNo){
        cout<<"Name      :"; cin>>ws;getline(cin,n->name);
        cout<<"Occuption :"; cin>>n->occu;
        cout<<"Ic Number :"; cin>>n->icNo;
        cout<<"Contact Number :"; cin>>n->contactNO;
        flag=1;
    }
    if(flag==0){
        cout<<"cannot found"<<endl;
    }

}
int main(){
    dailypass list;
    int choice;
    do{
        choice=list.menu();
        switch (choice) {
            case 1:
                list.newPass();
                break;
            case 2:
                list.displaypass();
                break;
            case 3:
                list.updatepass();
                break;


        }

    }while(choice!=99);
}
