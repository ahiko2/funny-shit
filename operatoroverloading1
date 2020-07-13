
#include<iostream>
 
using namespace std;

class complex
{
    private:
    int img,real;
    public:
    complex(){}
    complex(int i,int r)
    {
        real=r;
        img=i;
    }
    complex operator+(complex i)
    {
        complex temp;
        temp.img=img + i.img;
        temp.real=real + i.real;
        return temp;
    }
    void display()
    {
        cout<<real<<" + i"<<img<<endl;
    }
};
int main()
{
    complex c1(3,4);
    complex c2(4,3);
    complex c3;
    c3=c1.operator+(c2);
    c3=c1+c2;
    c3.display();

}
