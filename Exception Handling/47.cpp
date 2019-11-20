#include<iostream>
using namespace std;

class Stack{
private:
  int top;
  int size;
  int *arr;
public:
  Stack(): size(0), top(-1) {}
  Stack(int size1): size(size1), top(-1) {
    arr = new int[size];
  }
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
          return -1;
        }
    }
};

int main(){
  Stack s(5);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  return 0;
}
