#include<iostream>
using namespace std;

class Table{
	
	int r,c;
	int ** table;
	
	public:
	Table(): r(0), c(0) { initiate_table(); }
	Table(int x, int y): r(x), c(y) { initiate_table(); }
	
	void initiate_table(){
		table = new int*[r];
		for(int i = 0; i < r; i++){
			table[i] = new int[c];
		}
	}
	
	int get_r(){return r;}
	int get_c(){return c;}
	void set_r(int R){r = R;}
	void set_c(int C){c = C;}
	
	friend ostream& operator << (ostream &out, Table &t);
	friend istream& operator >> (istream &in, Table &t);
	
	int* operator[](int index){
		if(index < 0 || index >= r){
			cout << "Index out of range" << endl;
			exit(0);
		}
		return table[index];
	}
	
};

ostream& operator << (ostream &out, Table &t){
	for(int i = 0; i < t.r; i++){
		for(int j = 0; j < t.c; j++){
			out << t.table[i][j] << " "; 
		}
		out << endl;
	}
	return out;
}
	
istream& operator >> (istream &in, Table &t){
	int val;
	for(int i = 0; i < t.r; i++){
		for(int j = 0; j < t.c; j++){
			in >> val;
			t.table[i][j] = val;
		}
	}
	return in;
}

int main(){
	Table t(4, 5), t1(4, 5);
	cin >> t;
	t[0][0] = 5;
	int x = t[2][3];
	cout << x << endl;
	t1 = t;
	cout << t << endl << t1;
	return 0;
}
