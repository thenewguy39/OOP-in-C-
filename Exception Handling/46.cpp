#include <iostream>
using namespace std;

int main() {
	float a,b;
	try{
		cout << "Enter dividend and divisor :" << endl;
		cin >> a >> b;
		if(b == 0)
			throw b;
		cout << "Result  = " << a/b << endl;
	}
	catch(float b){
		cout << "Zero division error" << endl;
	}
	return 0;
}
