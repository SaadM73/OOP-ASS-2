#ifndef Q2_H_
#define Q2_H_
#include<iostream>
using namespace std;
class Matrix {
	int** matrix;
	int row;
	int col;

public:
	Matrix();// a default constructor
	Matrix(int, int);// a parametrized constructor
	Matrix(const Matrix&);// copy constructor
	void set(int i, int j, float val);//set value at (i,j)
	float get(int i, int j)const; //get value at (i,j)
	Matrix multiplyElement(const Matrix);//Elementwise multiplies two Matrices and returns the result
	void makeZero(); //if the any element in the matrix is zero than make the entire row and column zero.
	bool searchNumber(int number);
	void rotateBy90();
	int LeftDiagonalTotal();
	int RightDiagonalTotal();
	Matrix Merge(Matrix m);
	void input();
	void display();
	~Matrix();
};

#endif
