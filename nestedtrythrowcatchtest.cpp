#include <iostream>
using namespace std;

int main()
{
  try
  {
    
    try
    {
      try
      {
        try
        {
          throw "a character exception";
        }
        catch(const char* e)
        {
            cout<<"inner 1"<<endl;
            throw;
        }
      }
       catch(const char* e)
       {
        cout<<"inner 2"<<endl;
                    throw;

       }
    }
    catch(const char* e)
    {
      cout<<"inner 3"<<endl;
      throw runtime_error("dndn");
    }
    
  }
  catch(...)
  {
    cout<<"outer error"<<endl;
  }
  
  
}
/*
inner 1
inner 2
inner 3
inner 4
*/
