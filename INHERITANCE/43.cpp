#include<iostream>
using namespace std;
#define PI 3.14159

class Shape2D{
public:
  virtual float area() = 0;
  virtual float perimeter() = 0;
  virtual void display() = 0;
};

class Circle:public Shape2D{
private:
  float radius;
public:
  Circle():radius(0.0) { }
  Circle(float r): radius(r) { }
  float area() { return PI*radius*radius; }
  float perimeter() { return 2.0*PI*radius; }
  void display(){
    cout <<"Shape : Circle" << endl;
    cout <<"Area = "<< area() << endl;
    cout <<"Perimeter = " << perimeter() << endl;
  }
};

class Rectangle:public Shape2D{
private:
  float l,b;
public:
  Rectangle():l(0.0),b(0.0) { }
  Rectangle(float length, float breadth): l(length), b(breadth) { }
  float area() { return l*b; }
  float perimeter() { return 2.0*(l+b); }
  void display(){
    cout << "Shape : Rectangle" << endl;
    cout << "Area = "<< area() << endl;
    cout << "Perimeter = " << perimeter() << endl;
  }
};

int main(){
  Shape2D **p = new Shape2D*[5];
  p[0] = new Circle(5.0);
  p[1] = new Circle(3.0);
  p[2] = new Circle(4.0);
  p[3] = new Rectangle(5.0, 2.0);
  p[4] = new Rectangle(6.0, 3.0);
  for(int i=0;i<5;i++){
    p[i]->display();
    cout<<endl;
  }
  return 0;
}
