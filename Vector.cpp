#include<iostream>
using namespace std;

class Matrix;
class Vector;

class Vector {
	private :
		int numOfElement;
		int vector[20];
	public :
		void inputVector();
		friend void outputVector(const Vector &vectorOb);
		friend Vector product(const Matrix &matrixOb , const Vector &vectorOb);
};

class Matrix {
	private :
		int numOfEleInMatrix;
		int matrix[20][20];
	public :
		void inputMatrix();
		friend void outputMatrix(const Matrix &matrixOb);
		friend Vector product(const Matrix &matrixOb , const Vector &vectorOb);
};

void Vector::inputVector() {
	cout << "Nhap so luong phan tu trong vector : ";
	cin >> this->numOfElement;
	for (int i=0 ; i<this->numOfElement ; i++) {
		cout << "Nhap vao vector["<<i<<"] : ";
		cin >> this->vector[i];
	}
}

void Matrix::inputMatrix() {
	cout << "Nhap so luong phan tu trong ma tran (so hang = so cot) : ";
	cin >> this->numOfEleInMatrix;
	for(int i=0 ; i<this->numOfEleInMatrix ; i++) {
		for(int j=0 ; j<this->numOfEleInMatrix ; j++) {
			cout << "Nhap vao matrix["<<i<<"]["<<j<<"] : ";
			cin >> this->matrix[i][j];
		}
	}
}

Vector product(const Matrix &matrixOb , const Vector &vectorOb) {
	Vector newVector;
	int number = matrixOb.numOfEleInMatrix;
	if(number != vectorOb.numOfElement) {
		return vectorOb;
	}
	newVector.numOfElement = number;
	for(int i=0 ; i<number ; i++) {
		newVector.vector[i] = 0;
		for(int j=0 ; j<number ; j++) {
			newVector.vector[i] += vectorOb.vector[j] * matrixOb.matrix[i][j];
		}
	}
	return newVector;
}

void outputVector(const Vector &vectorOb) {
	cout << "\n\n";
	for(int i=0 ; i<vectorOb.numOfElement ; i++) {
		cout << vectorOb.vector[i] << "   ";
	}
}

void outputMatrix(const Matrix &matrixOb) {
	cout << "\n\n";
	for(int i=0 ; i<matrixOb.numOfEleInMatrix ; i++) {
		cout << "\n";
		for(int j=0 ; j<matrixOb.numOfEleInMatrix ; j++) {
			cout << matrixOb.matrix[i][j]<<"  ";
		}
	}
}

int main() {
	Matrix matrixOb;
	Vector vectorOb,vectorProduct;
	vectorOb.inputVector();
	matrixOb.inputMatrix();
	cout << "\n\n";
	cout << "MA TRAN : \n\n";
	outputMatrix(matrixOb);
	cout << "\n\n";
	cout << "\nVector : \n\n";
	outputVector(vectorOb);
	cout << "\n\n";
	vectorProduct = product(matrixOb,vectorOb);
	cout << "\n\n\nTich cua vector nhan ma tran : \n";
	outputVector(vectorProduct);
	cout << "\n";
	return 0;
}
