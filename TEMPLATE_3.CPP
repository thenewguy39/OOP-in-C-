#include<iostream>
using namespace std;

class Complex{
	float real;
	float imag;

	public:
	Complex(): real(0), imag(0) {}
	Complex(float r, float i): real(r),imag(i) {}
	
	friend ostream& operator << (ostream &out, Complex c);
	
};

ostream& operator << (ostream &out, Complex c){
    out << c.real << " + i" << c.imag;
    return out;
}

template <typename T>
class Stack{
    int top;
    int size;
    T *arr;

public:
    Stack(): size(0), top(-1) {}
    Stack(int size1): size(size1), top(-1) { arr = new T[size]; }
  
    int isEmpty(){ return top == -1; }
    int isFull(){ return size-1 == top; }
  
    void push(T x){
        try {
            if(isFull()) throw 0;
            	arr[++top] = x;
        }
        catch(int) {
            cout<<"Stack Overflow!"<<endl;
        }
    }

    T pop(){
        try {
            if(isEmpty()) throw 0;
            	return arr[top--];
        }
        catch(int) {
            cout<<"Stack Underflow!"<<endl;
            T junk;
            return junk;
        }
    }
};

int main(){
	Stack<int> si(10);
	si.push(1);
	si.push(2);
	si.push(3);
	si.push(4);
	si.push(5);
	si.push(6);
	cout << si.pop() << endl;
	
	Stack<Complex> sc(10);
	sc.push(Complex(1,1));
	sc.push(Complex(2,2));
	sc.push(Complex(3,3));
	sc.push(Complex(4,4));
	sc.push(Complex(5,5));
	sc.push(Complex(6,6));
	cout << sc.pop() << endl;
	
	while(!si.isEmpty()){
		cout << si.pop() << " " << endl;
	}
	cout << endl;

	while(!sc.isEmpty()){
		cout << sc.pop() << " " << endl;
	}
	cout << endl;
  
  return 0;
}
