#include<iostream>
using namespace std;
#define PI 3.14159

class Shape {
public:
  virtual float getArea() = 0;
  virtual void display() = 0;
};

class TwoDShape: public Shape {
public:
  virtual float getArea() = 0;
  virtual void display() = 0;
};

class ThreeDShape: public Shape {
public:
  virtual float getArea() = 0;
  virtual float getVolume() = 0;
  virtual void display() = 0;
};

class Circle: public TwoDShape {
private:
  float radius;
public:
  Circle(): radius(0.0) {}
  Circle(float r): radius(r) {}
  float getArea() { return PI*radius*radius; }
  void display() {
    cout << "Shape : Circle" << endl;
    cout << "Area = " << getArea() << endl;
  }
};

class Triangle: public TwoDShape {
private:
  float base, height;
public:
  Triangle():base(0.0),height(0.0) {}
  Triangle(float a, float b):base(a),height(b) {}
  float getArea() { return 0.5*base*height; }
  void display() {
    cout << "Shape : Triangle" << endl;
    cout << "Area = "<<getArea() << endl;
  }
};

class Ellipse: public TwoDShape {
private:
  float a, b;
public:
  Ellipse():a(0.0),b(0.0) {}
  Ellipse(float x, float y):a(x),b(y) {}
  float getArea() { return PI*a*b; }
  void display() {
    cout << "Shape : Ellipse" << endl;
    cout << "Area = "<<getArea() << endl;
  }
};

class Sphere: public ThreeDShape {
private:
  float r;
public:
  Sphere():r(0.0) {}
  Sphere(float radius):r(radius) {}
  float getArea() { return 4.0*PI*r*r; }
  float getVolume() { return 4.0*PI*r*r*r/3.0; }
  void display() {
    cout << "Shape : Sphere" << endl;
    cout << "Surface Area = " << getArea() << endl;
    cout << "Volume = " << getVolume() << endl;
  }
};

class Cube: public ThreeDShape {
private:
  float s;
public:
  Cube():s(0.0) {}
  Cube(float side):s(side) {}
  float getArea() { return 6.0*s*s; }
  float getVolume() { return  s*s*s; }
  void display() {
    cout << "Shape : Cube" << endl;
    cout << "Surface Area = " << getArea() << endl;
    cout << "Volume = " << getVolume() << endl;
  }
};

int main() {
  Shape** p = new Shape*[5];
  p[0] = new Circle(3.0);
  p[1] = new Triangle(7.0, 5.0);
  p[2] = new Ellipse(4.0, 7.0);
  p[3] = new Sphere(5.0);
  p[4] = new Cube(8.0);
  for(int i = 0; i < 5; i++){
    p[i]->display();
    cout<<endl;
  }
  return 0;
}
