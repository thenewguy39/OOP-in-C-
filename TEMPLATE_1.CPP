#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

class Complex{
	float real;
	float imag;

	public:
	Complex(float r, float i): real(r),imag(i) {}
	
	bool operator >= (Complex &c){
        if(real*real + imag*imag >= c.real*c.real + c.imag*c.imag){
            return true;
        }
        return false;
	}
	
	friend ostream& operator << (ostream &out, Complex c);
	
};

ostream& operator << (ostream &out, Complex c){
    out << c.real << " + i" << c.imag;
    return out;
}

class String{
    char *str;
    
    public:
    String(char *a): str(a) {}
    
    bool operator >= (String s2){
        if(strcmp(str, s2.str) >= 0)
            return true;
        return false;
    }
    
    friend ostream& operator << (ostream &out, String s);

};

ostream& operator << (ostream &out, String s){
    int i=0;
    while(s.str[i] != '\0'){
        out << s.str[i++];
    }
    out << endl;
    return out;
}

template <class T>
T maximum(T ele1, T ele2){
    if(ele1>=ele2)
        return ele1;
    else
        return ele2;
}

int main(){
    int num1 = 5, num2 = 9;
    cout << maximum(num1,num2) << endl;
    
    Complex c1(5, 3), c2(2, 4);
    cout << maximum(c1, c2) << endl;
    
    String str1("HELLO") , str2("WORLD");
    cout << maximum(str1, str2) << endl;
    
    return 0;
}
