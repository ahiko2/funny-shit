#include <iostream>
#include <string>
using namespace std;
//basic employe part

class employe
{   private:
    int idnumber;
    string name;
    public:
    employe(int id,string name)
    {
        this->idnumber=id;
        this->name=name;
    }
    //showing result
    int getidnumber(){return idnumber;}
    string getname(){return name;}
};
//1st is fulltimerpart

class ParttimeEmployee: public employe
{
private:
int wage;
public:
ParttimeEmployee(int e,string n,int w):employe(e,n)
{
wage=w;
}
int getWage(){return wage;}
};

class fulltimeperson:public employe
{   
    private:
    int salary;
    public:
    fulltimeperson(int id,string name,int sal):employe(id,name)
    {
        this->salary=sal;
    }
    int getsalary(){return salary;}

};
int main()
{   int payment1,payment2;
    string name1="john";
    string name2="icezz";
    
    cin>>payment1;
    fulltimeperson f1(1334,name1,payment1);
    ParttimeEmployee p1(32,name2,payment2);

    cout<<f1.getname()<<f1.getsalary();


}
