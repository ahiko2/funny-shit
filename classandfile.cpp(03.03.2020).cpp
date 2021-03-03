#include <iostream>
#include <fstream>
using namespace std;
class itemm{
    
	private:
	string name;
	int price,qty;
	public:
    itemm(){}
	itemm(string n,int p,int q){
		name=n;
		price=p;
		qty=q;
	}
    //input data to file
    friend ifstream & operator>>(ifstream &ifs,itemm &i);
    //output data to file
    friend ofstream & operator<<(ofstream &ofs,itemm &i);
    //cout managing
    friend ostream & operator<<(ostream &ost,itemm &i);
    
    

};
ifstream & operator>>(ifstream &ifs,itemm &i){
        ifs>>i.name>>i.price>>i.qty;
        return ifs;
    }
ofstream & operator<<(ofstream &ofs,itemm &i){
    ofs<<i.name<<endl;
    ofs<<i.price<<endl;
    ofs<<i.qty<<endl;
    return ofs;
}
ostream & operator<<(ostream &ost,itemm &i){
    ost<<"Name      "<<i.name<<endl;
    ost<<"price     "<<i.price<<endl;
    ost<<"quantity  "<<i.qty<<endl;

    return ost;
}
    
    
int main(){
    string name;
    int count,price,qty;
    cout<<"Number of Itemms :";
    cin>>count;
    itemm *list[count];
    for(int i=0;i<count;i++){
    cout<<"Enter "<<i+1<<endl;
    cout<<" Itemm Name , price and quantity"<<endl;
    cin>>name;
    cin>>price;
    cin>>qty;
    list[i]=new itemm(name,price,qty);
    }
    ofstream ofs("my.txt");
    if(!ofs.is_open())
        cout<<"Unable to Create";
    for(int i=0;i<count;i++){
        ofs<<*list[i];
    }
    itemm item;
    ifstream ifs("my.txt");
    if(!ifs.is_open())
        cout<<"cannot open file";
    for(int i=0;i<count;i++)
    {
        ifs>>item;
        cout<<i+1<<endl<<item<<endl;
    }
  
}
