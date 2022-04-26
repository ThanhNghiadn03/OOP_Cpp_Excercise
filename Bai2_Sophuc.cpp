#include<iostream>
using namespace std;

class Sophuc {
	private :
		int thuc;
		int ao;
	public :
		friend ostream & operator << (ostream &os , Sophuc &sophucOb);
		friend istream & operator >> (istream &is , Sophuc &sophucOb);
		friend Sophuc operator + (Sophuc &sophucOb1 , Sophuc &sophucOb2);
		friend Sophuc operator - (Sophuc &sophucOb1 , Sophuc &sophucOb2);
};

istream & operator >> (istream &is , Sophuc &sophucOb) {
	cout << "Nhap vao phan thuc : ";
	is >> sophucOb.thuc;
	cout << "Nhap vao phan ao : ";
	is >> sophucOb.ao;
}

ostream & operator << (ostream &os , Sophuc &sophucOb) {
	os << sophucOb.thuc << " + ";
	if (sophucOb.ao < 0) {
		os << "(" << sophucOb.ao << ")i "; 
	} else {
		os << sophucOb.ao << "i";
	}
}

Sophuc operator + (Sophuc &sophucOb1 , Sophuc &sophucOb2) {
	Sophuc sum;
	sum.thuc = sophucOb1.thuc + sophucOb2.thuc;
	sum.ao = sophucOb1.ao + sophucOb2.ao;
	return sum;
}

Sophuc operator - (Sophuc &sophucOb1 , Sophuc &sophucOb2) {
	Sophuc dif;
	dif.thuc = sophucOb1.thuc - sophucOb2.thuc;
	dif.ao = sophucOb1.ao - sophucOb2.ao;
	return dif;
}

int main() {
	Sophuc sophucOb1;
	cin >> sophucOb1;
	Sophuc sophucOb2;
	cin >> sophucOb2;
	cout << "\n\n";
	cout << sophucOb1 << endl;
	cout << sophucOb2 << endl;
	Sophuc sum;
	sum = sophucOb1 + sophucOb2;
	cout << "Tong cua 2 so phuc la : ";
	cout << sum;
	Sophuc dif;
	dif = sophucOb1 - sophucOb2;
	cout << "\n\nHieu cua 2 so phuc la : ";
	cout << dif;
	return 0;
}
