#include<iostream>
using namespace std;

class Phanso {
	private :
		int tu;
		int mau;
	public :
		friend ostream & operator << (ostream &os , Phanso &phansoOb);
		friend istream & operator >> (istream &is , Phanso &phansoOb);
		friend Phanso operator + (Phanso &phansoOb1 , Phanso &phansoOb2);
		friend Phanso operator - (Phanso &phansoOb1 , Phanso &phansoOb2);
		friend Phanso operator * (Phanso &phansoOb1 , Phanso &phansoOb2);
		friend Phanso operator / (Phanso &phansoOb1 , Phanso &phansoOb2);
		friend Phanso rutgon(Phanso &phansoOb);
};


istream & operator >> (istream &is , Phanso &phansoOb) {
	cout << "Nhap vao tu : ";
	is >> phansoOb.tu;
	do {
		cout << "Nhap vao mau : ";
		is >> phansoOb.mau;
	} while(phansoOb.mau == 0);
}

ostream & operator << (ostream &os , Phanso &phansoOb) {
	os << phansoOb.tu << " / " << phansoOb.mau << endl;
}

Phanso operator + (Phanso &phansoOb1 , Phanso &phansoOb2) {
	Phanso sumPhanso ;
	sumPhanso.tu = phansoOb1.tu*phansoOb2.mau + phansoOb1.mau*phansoOb2.tu;
	sumPhanso.mau = phansoOb1.mau * phansoOb2.mau;
	return sumPhanso; 
}

Phanso operator - (Phanso &phansoOb1 , Phanso &phansoOb2) {
	Phanso difPhanso ;
	difPhanso.tu = phansoOb1.tu*phansoOb2.mau - phansoOb1.mau*phansoOb2.tu;
	difPhanso.mau = phansoOb1.mau * phansoOb2.mau;
	return difPhanso; 
}

Phanso operator * (Phanso &phansoOb1 , Phanso &phansoOb2) {
	Phanso mul ;
	mul.tu = phansoOb1.tu*phansoOb2.tu;
	mul.mau = phansoOb1.mau*phansoOb2.mau;
	return mul; 
}

Phanso operator / (Phanso &phansoOb1 , Phanso &phansoOb2) {
	Phanso div ;
	div.tu = phansoOb1.tu*phansoOb2.mau;
	div.mau = phansoOb1.mau*phansoOb2.tu;
	return div; 
}

Phanso rutgon(Phanso &phansoOb) {
	int a = phansoOb.tu;
	int b = phansoOb.mau;
	if (a==0) {
		return phansoOb;
	}
	while(a!=b) {
		if (a>b) {
			a = a-b;
		} else {
			b = b-a;
		}
	}
	phansoOb.tu = (phansoOb.tu)/a;
	phansoOb.mau = (phansoOb.mau)/a;
	return phansoOb;
}

int main() {
	Phanso phansoOb;
	cin >> phansoOb;
	cout << phansoOb;
	Phanso phansoOb1;
	cin >> phansoOb1;
	cout << phansoOb1;
	cout << "\n\nTinh tong 2 phan so : ";
	Phanso sum;
	sum = phansoOb1 + phansoOb;
	rutgon(sum);
	cout << sum;
	cout << "\n\nTinh hieu 2 phan so : ";
	Phanso dif;
	dif = phansoOb1 - phansoOb;
	rutgon(dif);
	cout << dif;
	cout << "\n\nTinh tich 2 phan so : ";
	Phanso mul;
	mul = phansoOb1*phansoOb;
	rutgon(mul);
	cout << mul;
	cout << "\n\nTinh thuong 2 phan so : ";
	Phanso div;
	div = phansoOb1/phansoOb;
	rutgon(div);
	cout << div;
	return 0;
}
