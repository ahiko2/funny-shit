
#include<iostream>
 using namespace std;

class rational
{
    private:
    int p,q;
    public:
    rational( int p=0,int q=0)
    {
        this->p=p;
        this->q=q;
    }
    rational operator+(rational r)
    {
        rational temp(0,0);
        temp.p=p*r.p + q*r.p;
        temp.q=q*r.q;
        return temp;
    }
    friend ostream & operator<<(ostream &o,rational &r1);
    

};
ostream & operator<<(ostream &o,rational &r1)
{
    o<<r1.p<<" / " <<r1.q;
    return o;
}
int main()
{
    rational r1(3,4),r2(4,5),r3;
    r3=r1+r2;
    cout<<r1<<" + "<<r2 <<" = ";
    cout<<r3<<endl;
    
}
