
#include<iostream>
 using namespace std;

class rational
{
    private:
    int p,q;
    public:
    rational(int p=0,int q=0)
    {
        this->p=p;
        this->q=q;
    }
    rational operator+(rational r)
    {
        rational temp;
        temp.p=p*r.q + q*r.p;
        temp.q=r.q*q;
        return temp;
    }
    friend ostream & operator<<(ostream & out, rational c1); //printing function

};
ostream & operator<<(ostream & out, rational c1)
{
    out<<c1.p <<"/"<<c1.q;
    return out;
}
int main()
{
    rational r1(3,4),r2(2,5),r3;
    r3=r1+r2;
    cout<<r1<<" + "<<r2 <<" = ";
    cout<<r3<<endl;

}
