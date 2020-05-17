#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;


int main()
{
    string line1 = "";
    cin>>line1;
    string line2="";
    //change line2 size to line1
    int len=(int)line1.length();
    line2.resize(len);

    for(int i = 0, j = len -1; i<len;i++,j-- )
    {
        line2[i]=line1[j];
    }
    //j = len -1 meaning ka string tway yae a sone hmr \0 so tr shi tal.
    //counting is 0,1,2,3,4. Not 0,1,2,3,4,5,6
    line2[len]='\0';
    cout<<line2<<endl;
   if(line1.compare(line2)==0)
   {
       cout<<"yes";
   }
   else
   {
      cout<<"No";
       
   }
}
