#include<iostream>
#include<cmath>
using namespace std;
int dis0(int,int);
int dbig0roo1(int,int,int);
int dbig0roo2(int,int,int);
int dless0roo1(int,int);
int dless0roo2(int,int,int);
int main()
{
    int a,b,c,d;
    float roo,roo1,roo2;
    cout<<"enter x y,z"<<endl;
    cin>>a>>b>>c;
    d=b * b - 4 * a * c;
    
    if(d==0)
    {
        roo=dis0( b, a);
        cout<<"Roots are real & equal"<<endl;
    }
    else if(d > 0)
    {
        roo1=dbig0roo1(a, b, c);
        
        roo2=dbig0roo2(a, b, c);
            cout<<"Roots are real & distinct"<<endl;
    }
    else
    {
        roo1=dless0roo1(a, b);
         roo1=dless0roo2(a, b , c);
        cout<<"Roots are imaginary"<<endl;
    }
    return 0;
}
int dis0(int x,int y)
{
    int roo;
    roo=(-x)/(2*y);
    cout <<" root = "<<roo<<endl;
    
    return roo;
}
int dbig0roo1(int a,int b,int c)
{
    int roo1;
    roo1=-(b+sqrt(b * b - 4 * a * c))/(2*a);
        cout  <<"root1 ="<< roo1<<endl;
   
    
    return roo1;
  
}
int dbig0roo2(int a,int b,int c)
{
    int roo2;
       roo2=-(b-sqrt(b * b - 4 * a * c))/(2*a);
          cout <<"root2 ="<< roo2<<endl;
    
      return roo2;
}
int dless0roo1(int a,int b)
{
    int roo1;
    roo1=(-b)/(2*a);
   cout  <<"root1 ="<< roo1<<endl;
    return roo1;
}
int dless0roo2(int a,int b,int c)
{
    int roo2;
    roo2=sqrt(-(b * b - 4 * a * c))/(2*a);
    cout <<"root2 ="<< roo2<<endl;
    
    return roo2;
}
