//TransferParameters
#include<iostream>
using namespace std;

/* Передача параметров в функцию
1.По значению (by value)
2. По указателю (by pointer)
3. По ссылке (by reference)
*/

//void Exchange(int a, int b);
//void Exchange(int* a, int* b);
void Exchange(int& a, int& b);

void main()
{
	setlocale(LC_ALL, "");
	int a = 2, b = 3;
	cout << a << "\t" << b << endl;
	Exchange(a, b);
	cout << a << "\t" << b << endl;
}
//void Exchange(int a, int b)
//void Exchange(int* a, int* b)
void Exchange(int& a, int& b)
{
	int buffer = a;
	a = b;
	b = buffer;
	//cout << a << "\t" << b << endl;
}
