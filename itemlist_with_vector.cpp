#include<iostream>
#include <vector>
#include <fstream>
using namespace std;
//declare class here
class Item{
	private:
	int item_code;
	string item_name;
	public:
	Item(){}
	Item(int c,string n){
		item_code=c;
		item_name=n;
	}
	int returnitem_code(){
		return item_code;
	}
	string returnitem_name(){
		return item_name;
	}
	friend ostream & operator<<(ostream &os,Item &i);
 	friend ifstream & operator>>(ifstream &fis,Item &i);
 	friend ofstream & operator<<(ofstream &fos,Item &i);
};

int main(){
	system("clear");
	int YesorNo=1;
	int item_code,count=0;
	string item_name;
	
	vector<Item *> list;
	cout<<"item code: (or) press 0 to terminate :"; cin>>item_code;
	while(item_code!=0){
		cout<<"item name :"; cin>>item_name;
		count++;
		list.push_back(new Item(item_code,item_name));
		cout<<"item_code :"; cin>>item_code;

	}

	//direct print the result without using file object
	//dammit, vectors are too useful
	/*
	vector<Item *>::iterator itr;

	for(itr=list.begin();itr!=list.end();itr++){
		cout<<**itr;
		
	}
	*/

	

	

	ofstream fos("Items.txt");
	vector<Item *>::iterator itr;

	for(itr=list.begin();itr!=list.end();itr++){
		fos<<**itr;
		
	}
	
	fos.close();
	//displaying result
	Item itemdisplay;
	ifstream ifs("Items.txt");

	for(int i=0;i<count;i++){
		ifs>>itemdisplay;
		cout<<"item number :"<<i+1<<endl;
		cout<<itemdisplay<<endl;
	}
	
	


	
}
ostream & operator<<(ostream &os,Item &i){
    os<<"item_code      "<<i.item_code<<endl;
    os<<"item_name     "<<i.item_name<<endl;
   	return os;
	}
ifstream & operator>>(ifstream &fis,Item &i)
{
 fis>>i.item_code>>i.item_name;
 return fis;
}
ofstream & operator<<(ofstream &fos,Item &i){
	fos<<i.item_code<<endl<<i.item_name<<endl;
	return fos;
}
