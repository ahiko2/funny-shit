#include <iostream>
using namespace std;

int FirstFactorial(int num) { 
	// set the limit to the number provided   
	int limit = num;
	for (int i = 1; i < limit; ++i) {
  		num = num * i;
	}
  	return num; 
}

int main() { 
  
	cout << FirstFactorial(4);
  	return 0;
}   
