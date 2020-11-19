#include <iostream>
#include <exception>
using namespace std;

class overspeed:public exception{
    private:
    int speed;
    public:
    void setspeed(int speed)
    {
        this->speed=speed;
    }
    void getspeed(int speed)
    {
        cout<<"current speed is "<<speed<<endl;
    }
    const char * what()
    {
        return "check ur speed AGAIN";
    }
};

class Car{
    private:
    int speed;
    public:
    Car(){
        speed=0;
        cout<<"speed is"<<speed<<endl;
    }
    void accerelate(){
        for(;;){
            speed+=10;
            cout<<"speed is "<<speed<<endl;
            if(speed>=100){
                overspeed s;
                s.setspeed(speed);
                throw s;
            }
        }
    }
};

int main(){
    Car annia;
    try{
        annia.accerelate();
    }
    catch(overspeed s){
        cout<<s.what()<<endl;
    }
}
/*
void deacce(){
        for(;;){
            speed-=10;
            cout<<"reducing ="<<speed<<endl;
            if(speed==30){
                stable st;
                st.setspeed(speed);
                throw st;

            }
        }
    }
*/
