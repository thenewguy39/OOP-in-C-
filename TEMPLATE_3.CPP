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

class Stack{
    int top;
    int size;
    int *arr;

    public:
    Stack(): size(0), top(-1) {}
    Stack(int size1): size(size1), top(-1) { arr = new int[size]; }

    int isEmpty(){ return top == -1; }
    int isFull(){ return size-1 == top; }

    void push(int x){
        try {
            if(isFull()) throw 0;
                arr[++top] = x;
        }
        catch(int) {
            cout<<"Stack Overflow!"<<endl;
        }
    }

    int pop(){
        try {
            if(isEmpty()) throw 0;
                return arr[top--];
        }
        catch(int) {
            cout<<"Stack Underflow!"<<endl;
            return 0;
        }
    }
    friend ostream& operator << (ostream &out, Stack s);
};

ostream& operator << (ostream &out, Stack s){
        for(int i  = 0; i < s.size; i++){
                out << s.arr[i] << " ";
        }
        out << endl;
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

    cout << "Initial stacks:" << endl;
    Stack s1(5), s2(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << s1;
    s2.push(4);
    s2.push(5);
    s2.push(6);
    cout << s2;

    cout << "After swapping: " << endl;
    Swap(s1, s2);
    cout << s1;
    cout << s2;

    return 0;
}
