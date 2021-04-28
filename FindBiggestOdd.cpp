#include <iostream>
#include <cstdio>
using namespace std;


void find_max_num(){
    int arr[100],max_odd=0;
    int arr_size; cout<<"Enter array size :";cin>>arr_size;
    cout<<"Enter "<<arr_size<<" number :";
    //data input
    for(int i=0;i<arr_size;i++){
        cin>>arr[i];
    }
    
    //data check where num is odd or not
    for(int i=0;i<5;i++){
		if(arr[i]%2!=0)
		{
			if(arr[i]>max_odd)
				max_odd=arr[i];
		}
		
	}
    if(max_odd==0){
		cout<<"no big odd"<<endl;
	}
	else
		cout<<"max :"<<max_odd<<endl;





}

int main(){
    int check_point; 
    cout<<"click any key to start or 0 to terminate the problem:"; cin>>check_point;
    while(check_point!=0){
        
        find_max_num();
    cout<<"click any key to restart or 0 to terminate the problem:"; cin>>check_point;


    }
    if(check_point==0)
        cout<<"problem terminated"<<endl;
    
   


}
