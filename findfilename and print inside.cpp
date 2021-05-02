#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main () {

    string FN;
    cin>>FN;



  string myText;
  int roll;

  ifstream MyReadFile(FN+".txt");

  MyReadFile>>myText>>roll;
  cout<<myText<<endl;
  cout<<roll<<endl;
  // Close the file
  MyReadFile.close();
}
