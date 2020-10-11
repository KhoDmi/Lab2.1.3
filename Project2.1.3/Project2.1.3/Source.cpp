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
	//test1.getMatrix();
	Matrix test2(2, 3);
	test2.getMatrix();
	Matrix test3(test2);
	test3.getMatrix();

	cout << test2 << endl;

	Matrix test0 = test2 + test3;
	test0.getMatrix();

	if (test0 > test2) cout << "yes" << endl;
	else cout << "no" << endl;

	if (test0 < test3)cout << "yes" << endl;
	else cout << "no" << endl;













	return 0;
}
