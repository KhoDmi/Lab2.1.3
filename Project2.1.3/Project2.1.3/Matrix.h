#include<string>
#include<limits>
#ifndef MATRIX_H
#define MATRIX_H

using std::string;
using std::ostream;

class Matrix
{
public:
	friend ostream& operator<<(ostream &out, const Matrix& m);
	friend ostream& operator<<(ostream &out, double& m);
	friend ostream& operator<<(ostream &out, int& m);

	const Matrix operator+(const Matrix& r);
	bool operator<(const Matrix& r);
	bool operator>(const Matrix& r);

	Matrix();
	Matrix(int i, int j);
	Matrix(const Matrix& existingÙne);

	void fillMatrix();
	void getMatrix();
	void fillElement(int i, int j);
	void getElement(int i, int j);
	double** element;
	~Matrix();
private:
	int numofStrings;
	int numofColomns;
	//
};

#endif MATRIX_H

