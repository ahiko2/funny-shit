#include <iostream>
#include <exception>
#include <cstring>
using namespace std;

class badlength:public exception
{
    private:
    int N;
    public:
    badlength(int N)
    {
        this->N=N;
    }
    int what(){
        cout<<"short"<<endl;
        return N;
    }
};
int main(){
    char str[256];
    scanf("%s",str);
    cout<<str<<endl;
    int len1=strlen(str);
    cout<<len1;
    
    
    try
    {
        if(len1<5){
            throw badlength(len1);
        }
        else
        {
            cout<<"ok, good to go"<<endl;
        }
        
    }
    catch(badlength e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}
