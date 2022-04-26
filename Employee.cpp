#include<iostream>

using namespace std;

class employee {
	public :
		string name,id;
		float salary;
		employee();
		float calculateSalary() {
			
		}
		void input();
		void output();
};
employee::employee() {
	this->name="";
	this->id="";
	this->salary= 0.0;
}

void employee::input() {
	cout << "Nhap vao id : ";
	cin >> this->id;
	cout << "Nhap vao ten : ";
	getline(cin, this->name);
	cout << "Nhap vao luong : ";
	cin >> this->salary
}

int main() {
	
	return 0;
}
