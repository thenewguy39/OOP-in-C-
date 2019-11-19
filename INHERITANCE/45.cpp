#include<iostream>
using namespace std;

class base {
public:
  base() { cout << "Base created \n"; }
  virtual ~base() { cout << "Base destroyed \n"; }
};

class derived: public base {
public:
  derived() { cout << "Derived created\n"; }
  ~derived() { cout << "Derived destroyed\n"; }
};

int main() {
  derived *d = new derived();
  base *b = d;
  delete b;
  return 0;
} 
