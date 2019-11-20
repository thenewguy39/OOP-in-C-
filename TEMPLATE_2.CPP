#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

class Complex{
	float real;
	float imag;

	public:
	Complex(): real(0),imag(0) {}
	Complex(float r, float i): real(r),imag(i) {}
	
	bool operator >= (Complex &c){
        if(real*real + imag*imag >= c.real*c.real + c.imag*c.imag){
            return true;
        }
        return false;
	}
	
	friend ostream& operator << (ostream &out, Complex &c);
	
};

ostream& operator << (ostream &out, Complex &c){
    out << c.real << " + i" << c.imag;
    return out;
}

template <class T>
void Swap(T &ele1, T &ele2){
    T temp;
    temp = ele1;
    ele1 = ele2;
    ele2 = temp;
}

int main(){
    int num1 = 5, num2 = 9;
    cout << "Swapping two integers" << endl;
    cout << "Initial values: num1 =" << num1 << ", num2=" << num2 << endl;
    Swap(num1, num2);
    cout << "Final values: num1 =" << num1 << ", num2=" << num2 << endl;

    Complex A(5,3), B(2,7);
    cout << "Swapping two complex numbers" << endl;
    cout << "Initial values: A =" << A << ", B=" << B << endl;
    Swap(A, B);
    cout << "Final values: A =" << A << ", B=" << B << endl;

    return 0;
}
