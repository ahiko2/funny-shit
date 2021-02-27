# include<iostream>
# include<fstream>
using namespace std;
     
//file writing
void createfile(){
    ofstream txt("my.txt");
    if(!txt.is_open()){
        cout<<"Unable to create file";
    }
    cout<<"file created"<<endl;
    txt<<"john"<<endl;
    txt<<"123"<<endl;
}
void readfile(){
    ifstream txt;
    txt.open("my.txt");
    if(!txt.is_open()) cout<<"Unable to open file";
    else
    {
        cout<<"file opened"<<endl;
        string name;
        int roll;
        txt>>name>>roll;
        txt.close();
        cout<<"name "<<name<<endl;
        cout<<"roll "<<roll<<endl;
    }
    
}
int main(){
    createfile();
    readfile();

}
