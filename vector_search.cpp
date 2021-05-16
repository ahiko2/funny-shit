
#include<iostream>
#include <vector>
using namespace std;
class student{
    public:
    string name;
    int id;
    student(int i,string n){
        id=i;
        name=n;
    }
    int getid(){
        return id;
    }
    string getname(){
        return name;
    }

};
int main ()
{   
    //declare student info
    student s1(11,"aa");
    student s2(22,"ba");
     student s3(33,"ca");
     student s4(44,"da");
     student s5(55,"ea");
     student s6(66,"fa");
     student s7(77,"ga");
    //input student info into vector
    vector<student> stu;
    stu.push_back(s1);
    stu.push_back(s2);
    stu.push_back(s3);
    stu.push_back(s4);
    stu.push_back(s5);
    stu.push_back(s6);
    stu.push_back(s7);

    //iterating vector
    //vector<student>::iterator itr;
    // for(itr=stu.begin();itr!=stu.end();itr++){
    //     cout<<itr->id;
    //     cout<<itr->name<<endl;
    // }
  
    //planning for search unit
  
    int sec=77;
    int flag=0;
    int size1=stu.size();
   // for loop
     for(int i=0;i<size1;i++){

         if(sec==stu[i].id) {
             cout << "found you ";
             cout << stu[i].name << endl;
             flag = 1;
         }
     }
     if(flag==0){
         cout<<"not found";
     }


    

}
