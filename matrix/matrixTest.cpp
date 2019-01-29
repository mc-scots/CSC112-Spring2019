#include <iostream>
#include "matrix.h"

using namespace std;


int main()
{	
	Matrix a(3,3);
	Matrix b(3,3);
	
	cout << "Enter matrix A (3x3)" << endl;
	cin >> a;

	cout << "Enter matrix B (3x3)" << endl;
	cin >> b;
	
	cout << "A+B" << endl
		 << a+b << endl << endl;
		 
	cout << "A-B" << endl
	     << a-b << endl << endl;
	
	cout << "A*B" << endl
	     << a*b << endl << endl;
}
