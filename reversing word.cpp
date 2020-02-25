
#include <iostream>
using namespace std;
 
string FirstReverse(string str) {

	string rstr;
	
	// loop through characters in str
	for (int i = 0; i < str.size(); ++i) {
		// add characters to the front of rstr
		rstr = str[i] + rstr;
	}
	return rstr;
}

int main() { 
	cout << FirstReverse("reverse me if you can") << endl;
	// result: "nac uoy fi em esrever"
	return 0;
}
