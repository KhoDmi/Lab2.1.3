#include<iostream>
#include<string>
#include<iomanip>
#include<limits>

#include"Matrix.h"
using namespace::std;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;



Matrix::Matrix()
{
	numofStrings = 2;
	numofColomns = 2;
	double** element = new double* [numofStrings];
	for (int count = 0; count < numofStrings; count++)
		element[count] = new double[numofColomns];
	for (int i = 0; i < numofStrings; i++)
		for (int j = 0; j < numofColomns; j++)
			element[i][j] = 0.0;
}



Matrix::Matrix(int i, int j) : numofStrings(i), numofColomns(j)
{
	double** element = new double* [numofStrings];
	for (int count = 0; count < numofStrings; count++)
		element[count] = new double[numofColomns];
	//for (int i = 0; i < numofStrings; i++)
	//	for (int j = 0; j < numofColomns; j++)
	//		element[i][j] = 0.0;
	fillMatrix();
}



Matrix::Matrix(const Matrix& m)
{

}



void Matrix::fillMatrix()
{
	for (int i = 0; i < numofStrings; i++)
		for (int j = 0; j < numofColomns; j++)
	do
	{
		cout << "Input element ["<<i<<"]["<<j<<"]" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> element[i][j];
	} while (cin.fail());
}



void Matrix::getMatrix()
{
	for (int i = 0; i < numofStrings; i++)
	{
		for (int j = 0; j < numofColomns; j++)
			cout << element[i][j] << "    ";
		cout << endl;
	}

}



void Matrix::fillElement(int i, int j)
{
	do
	{
		cout << "Input element [" << i << "][" << j << "] " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> element[i][j];
	} while (cin.fail());
}



void Matrix::getElement(int i, int j)
{
	cout << "element ["<<i<<"]["<<j<<"] "<<element[i][j] << "    " << endl;
}



const Matrix Matrix :: operator+(const Matrix& r)
{
	if ((this->numofStrings == r.numofStrings) && (this->numofColomns == r.numofColomns))
	{
		Matrix temp(r.numofStrings, r.numofColomns);
		for (int i = 0; i < r.numofStrings; i++)
			for (int j = 0; j < r.numofColomns; j++)
				temp.element[i][j] = this->element[i][j] + r.element[i][j];
		return temp;
	}
	else cout << "Impossible to add" << endl;
}



bool Matrix:: operator<(const Matrix& r)
{
	int templ = this->numofColomns * this->numofStrings;
	int tempr = r.numofColomns * r.numofStrings;
	return templ < tempr;
}



bool Matrix:: operator>(const Matrix& r)
{
	int templ=this->numofColomns* this->numofStrings;
	int tempr = r.numofColomns * r.numofStrings;
	return templ >tempr;
}



Matrix::~Matrix()
{
	for (int i = 0; i < numofStrings; i++)
		delete[] element[i];
	delete[] element;
}