#include<iostream>
#include<cstring>
using namespace std;

class Person{
private:
  char *name;
  int age, height;
public:
  Person():age(0),height(0){
    strcpy(name, "x");
  }
  Person(char* s, int a, int h):age(a),height(h) {
    name = s;
  }
  void set(char* n, int a, int h) {
    name = n;
    age = a;
    height = h;
  }
  char* getname() { return name; }
  int getage() { return age; }
  int getheight() { return height; }
  virtual void printDetails() {
    cout<<"Name:   "<<getname()<<endl;
    cout<<"Age:    "<<getage()<<endl;
    cout<<"Height: "<<getheight()<<endl;
  }
};

class Student:public Person {
private:
  int roll;
  int year;
public:
  Student():Person() {
    roll = 0;
    year = 0;
  }
  Student(char* n, int a, int h, int r, int y):Person(n,a,h) {
    roll = r;
    year = y;
  }
  void set(char* s, int a, int h, int r, int y) {
    Person::set(s,a,h);
    roll = r;
    year = y;
  }
  int getroll() { return roll; }
  int getyear() { return year; }
  void printDetails() {
    Person::printDetails();
    cout<<"Roll:   "<<getroll()<<endl;
    cout<<"Year:   "<<getyear()<<endl<<endl;
  }
};

int main(){
  Person a((char*)"abc",19,170);
  Student b((char*)"bcd",18,160,15,2018);
  cout<<"Test: \n\n";
  a.printDetails();
  cout<<endl;
  b.printDetails();
  Person **p=new Person*[4];
  p[0] = new Person((char*)"ABC", 19, 170);
  p[1] = new Person((char*)"BCD", 19, 180);
  p[2] = new Student((char*)"CDE", 20, 183, 26, 2019);
  p[3] = new Student((char*)"DEF", 20, 180, 28, 2019);
  cout<<endl<<endl;
  for(int i=0;i<4;i++){
    p[i]->printDetails();
    cout<<endl;
  }
  return 0;
}
