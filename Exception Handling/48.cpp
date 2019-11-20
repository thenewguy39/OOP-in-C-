#include<iostream>
using namespace std;

class vehicle {
private:
  int lane;
  int direction;
public:
  vehicle(): lane(0), direction(1) {}
  vehicle(int l, int dir): lane(l), direction(dir) {}
  ~vehicle() {}
  
  void setVehicle(int l, int dir){
    lane = l;
    direction = dir;
  }
  
  void display(){
    cout<<"Lane:      "<< lane <<endl;
    cout<<"Direction: "<< direction <<endl;
  }
  void collision(vehicle v){
    try {
      if(lane == v.lane && direction != v.direction) throw 1;
      cout<<"The vehicles will not collide."<<endl;
    }
    catch(int) {
      cout<<"Vehicles will collide."<<endl;
    }
  }
};

int main() {
  vehicle a, b, c, d, e, f;
  a.setVehicle(1,0);
  b.setVehicle(1,1);
  a.collision(b);
  c.setVehicle(2,0);
  d.setVehicle(2,0);
  c.collision(d);
  return 0;
}
