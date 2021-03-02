# include<iostream>
# include<fstream>
using namespace std;

class student{
    private:
    string name;
    int roll;
    string branch;
    public:
    student(){}
    student(string n,int r,string b){
        name=n;
        roll=r;
        branch=b;
    }
    //output file, create data and put the file in background
    friend ofstream & operator<<(ofstream &ofs,student &s);
    //input file, bring the data in front of editor
    friend ifstream & operator>>(ifstream &ifs,student &s);
    friend ostream & operator<<(ostream &os,student s);
};
ofstream & operator<<(ofstream &ofs,student &s)
{
    ofs<<s.name<<endl;
    ofs<<s.roll<<endl;
    ofs<<s.branch<<endl;

    return ofs;
}
ifstream & operator>>(ifstream &ifs,student &s){
    ifs>>s.name;
    ifs>>s.roll;
    ifs>>s.branch;
    return ifs;

}
ostream & operator<<(ostream &os,student s){
    os<<"name "<<s.name<<endl;
    os<<"roll "<<s.roll<<endl;
    os<<"branch "<<s.branch<<endl; 
    os<<endl;
    return os;
}
int main(){
    ofstream ofs("my.txt");
    student s1("john",345,"CDD");
    student s2("pal",345,"GCD");
    ofs<<s1;
    ofs<<s2;
    ofs.close();
    ifstream ifs("my.txt");
    ifs>>s1;
    ofs<<s2;
    cout<<s1;
    cout<<s2;

}
