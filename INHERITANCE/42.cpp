#include<iostream>
#include<cstring>
using namespace std;

class Employee{
private:
  char *name;
  int sal;
public:
  Employee():name((char*)"A"),sal(0) { }
  Employee(char *n, int s):name(n),sal(s) { }
  void set(char *n, int s){
    strcpy(name, n);
    sal = s;
  }
  char* getname() { return name; }
  int getsal() { return sal; }
  virtual void printDetails(){
    cout<<"Name:      "<<getname()<<endl;
    cout<<"Salary:    "<<getsal()<<endl;
  }
};

class Manager:public Employee {
private:
  int type;
public:
  Manager():Employee() {
    type = 0;
  }
  Manager(char* n, int s, int t):Employee(n,s){
    type = t;
  }
  void set(char* n, int s, int t){
    Employee::set(n,s);
    type = t;
  }
  int gettype() { return type; }
  void printDetails() {
    Employee::printDetails();
    cout<<"Type:      "<<gettype()<<endl;
  }
};

class Clerk:public Employee {
private:
  int allowance;
public:
  Clerk():Employee() {
    allowance = 0;
  }
  Clerk(char* n, int s, int a):Employee(n,s) {
    allowance = a;
  }
  void set(char* n, int s, int a){
    Employee::set(n,s);
    allowance = a;
  }
  int geta() { return allowance; }
  void printDetails() {
    Employee::printDetails();
    cout<<"Allowance: "<<geta()<<endl;
  }
};

int main() {
  Manager m((char*)"Manager01", 4000, 3);
  Clerk c((char*)"Clerk01", 2700, 400);
  m.printDetails();
  cout<<endl;
  c.printDetails();
  cout<<endl;

  Employee **p = new Employee*[6];

  p[0] = new Employee((char*)"Employee1", 1000);
  p[1] = new Employee((char*)"Employee2", 2000);
  p[2] = new Manager((char*)"Manager1", 3000, 2);
  p[3] = new Manager((char*)"Manager2", 4000, 1);
  p[4] = new Clerk((char*)"Clerk1", 1500, 500);
  p[5] = new Clerk((char*)"Clerk1", 2500, 700);

  int sum = 0;

  for(int i=0;i<6;i++){
    p[i]->printDetails();
    cout<<endl;
    sum += p[i]->getsal();
  }
  cout<<endl<<"Total Salary: "<<sum<<endl;
  return 0;
}
