#include<stdlib.h>;
#include<iostream>;
#include <limits>;

using namespace std;
#include"Matrix.h";
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;

ostream& operator<<(ostream &out, const Matrix& m)
{
	out << "Matrix size is:" <<m.numofStrings<<"by"<<m.numofColomns << endl;
	return out;
}

//ostream& operator<<(ostream& out, double& m)
//{
//	out << m << endl;
//	return out;
//}
//
//ostream& operator<<(ostream& out, int& m)
//{
//	out << m << endl;
//	return out;
//}



int  main()
{
	cin.clear();
	cout << "Input anything to start" << endl;
	cin.get();
	system("cls");

	Matrix test1;
	test1.getMatrix();
	cout << endl;

	Matrix test2(2, 3);
	test2.fillMatrix();
	test2.getMatrix();
	cout << endl;

	Matrix test3(test2);
	test3.getMatrix();
	cout << endl;

	cout << test2 << endl;

	Matrix test4(3, 3);
	cout << endl;

	Matrix test0 = test2 + test3;
	test0.getMatrix();

	if (test4 > test2) cout << "yes" << endl;
	else cout << "no" << endl;

	if (test4 < test3)cout << "yes" << endl;
	else cout << "no" << endl;

	test0.~Matrix();
	test1.~Matrix();
	test2.~Matrix();
	test3.~Matrix();
	test4.~Matrix();



	Matrix* p = new Matrix;
	Matrix* pc = new Matrix(*p);
	p->fillMatrix();
	p->getMatrix();
	cout << endl;
	pc->getMatrix();
	cout << endl;

	p->~Matrix();
	pc->~Matrix();

	cout << "input anything to continue" << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	system("cls");

	int reqNumofM = 0;
	do
	{
		cout << "input number of matrixes" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> reqNumofM;
	} while (cin.fail());

	Matrix* regis = new Matrix[reqNumofM];

	for (int count = 0; count < reqNumofM; count++)
	{
		cout << "Input matrix #" << count << endl;
		regis[count].fillMatrix();
	}

	int check = 0;

	do
	{
		cout << "do you want to change any matrix? (y or n)" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		char answer = getchar();
		if (answer == 'y')
		{
			int reqMt;
			do
			{
				cout << "input number of matrix" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> reqMt;
			} while (cin.fail());

			int check2 = 0;

			do
			{

				int check1=0;

				do
				{
					cout << "do you want to change entire matrix or 1 number? (e or 1)" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					char answer1 = getchar();
					if (answer1 == 'e') check1 = -1;
					if (answer1 == '1') check1 = 1;
				} while (cin.fail());

				if (check1 == 0)
					regis[reqMt].fillMatrix();

				if (check1 == 1)
				{
					int i = 0;
					int j = 0;
					do
					{
						cout << "input number of element" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin >> i >> j;
					} while (cin.fail());
					regis[reqMt].fillElement(i, j);
				}

				check1 = 0;

				do
				{
					cout << "do you want to change anything else here? (y or n)" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					char answer2 = getchar();
					if (answer2 == 'n') check2 = -1;
				} while (cin.fail());

				

			} while (check2 == 0);
			check2 = 0;
		}

		
		if (answer == 'n') check = -1;
	} while (check == 0);

	check = 0;

	do
	{
		cout << "do you want to get any matrix? (y or n)" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		char answer = getchar();
		if (answer == 'y')
		{
			int reqMt;
			do
			{
				cout << "input number of matrix" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> reqMt;
			} while (cin.fail());

			cout << "Matrix #" << reqMt << endl;
			regis[reqMt].getMatrix();
		}
		if (answer == 'n') check = -1;
	} while (check == 0);


	 


	return 0;
}
