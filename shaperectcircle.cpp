#include <iostream>
#include <ctime>
using namespace std;

class shape
{
  public:
  virtual float area()=0;
   virtual float perimeter()=0;

};
class rectangle:public shape
{
  private:
  float length;
  float breadth;
  public:
  //returning value from private
  rectangle(int len,int brea)
  {
    this->length=len;
    this->breadth=brea;
  }
  float area(){return length * breadth;}
  float perimeter(){return (2*(length+breadth));}

};
class circle:public shape
{
  private:
  float radius;
  public:
  circle(int rad)
  {
    this->radius=rad;
  }
  float area(){return (3.14 * radius *radius);}
  float perimeter(){return (2*3.14*radius);}
};
int main()
{
  int len,breath;
  cin>>len>>breath;
  shape *sh=new rectangle(len,breath);
  cout<<"area of rectangle :"<<sh->area()<<endl;
  cout<<"perimeter of rectangle :"<<sh->perimeter()<<endl;
}
