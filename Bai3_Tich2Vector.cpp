#include<iostream>
using namespace std;

class Matrix;
class Vector;

class Vector {
	private :
		int numOfEleVector;
		int vector[20];
	public :
		void inputVector();
		friend void outputVector(const Vector &vectorOb);
		friend Vector product( const Matrix &matrixOb ,const Vector &vectorOb);
};

class Matrix {
	private :
		int numOfEleMatrix;
		int matrix[20][20];
	public :
		void inputMatrix();
		friend void outputMatrix( const Matrix &matrixOb);
		friend Vector product(const Matrix &matrixOb , const Vector &vectorOb);
};

void Vector::inputVector() {
	cout << "Nhap vao so luong cac phan tu trong vector : ";
	cin >> this->numOfEleVector;
	for (int i=0 ; i<this->numOfEleVector ; i++) {
		cout << "Nhap vao phan tu vector["<< i << "] : ";
		cin >> this->vector[i];
	}
}

void Matrix::inputMatrix() {
	cout << "Nhap vao so luong hang va cot trong matrix (hang = cot)";
	cin >> this->numOfEleMatrix;
	for (int i=0 ; i<this->numOfEleMatrix ; i++) {
		for(int j=0 ; j<this->numOfEleMatrix ; j++) {
			cout << "Nhap vao phan tu matrix["<<i<<"]["<<j<<"] : ";
			cin >> this->matrix[i][j];
		}
	}
}

Vector product (const Matrix &matrixOb ,const Vector &vectorOb) {
	int number = vectorOb.numOfEleVector;
	if(matrixOb.numOfEleMatrix != number) {
		return vectorOb;
	}
	Vector newVector;
	newVector.numOfEleVector = number;
	for(int i=0 ; i<number ; i++) {
		newVector.vector[i] = 0;
		for(int j=0 ; j<number ; j++) {
			newVector.vector[i] += vectorOb.vector[i]*matrixOb.matrix[i][j];
		}
	}
	return newVector;
}

void outputVector(const Vector &vectorOb) {
	cout << "\n\nIn ra vector : \n\n";
	for(int i=0 ; i<vectorOb.numOfEleVector ; i++) {
		cout << vectorOb.vector[i] << "     ";
	}
}

void outputMatrix(const Matrix &matrixOb) {
	cout << "\n\nIn ra matrix : \n\n";
	for(int i=0 ; i<matrixOb.numOfEleMatrix ; i++) {
		cout << "\n";
		for(int j=0 ; j<matrixOb.numOfEleMatrix ; j++) {
			cout << matrixOb.matrix[i][j] << "     ";
		}
	}
}

int main() {
	Vector vectorOb,vectorProduct;
	Matrix matrixOb;
	vectorOb.inputVector();
	matrixOb.inputMatrix();
	cout << "VECTOR : \n\n";
	outputVector(vectorOb);
	cout << "\n\nMATRIX : \n\n";
	outputMatrix(matrixOb);
	vectorProduct = product(matrixOb,vectorOb);
	cout << "\n\nTICH MA TRAN VOI VECTOR : \n\n";
	outputVector(vectorProduct);
	cout << "\n\n";
	return 0;
}
