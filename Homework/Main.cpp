#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

template<typename T>
void FillRand(T arr[], const int n);
template<typename T>
void Print(T arr[], const int n);
template<typename T>
T* push_back(T arr[], int& n, int value);
template<typename T>
T* push_front(T arr[], int& n, int value);
template<typename T>
T* insert(T arr[], int& n, int value, int& index);
template<typename T>
T* pop_back(T arr[], int& n);
template<typename T>
T* pop_front(T arr[], int& n);
template<typename T>
T* erase(T arr[], int& n, int& index);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	cout << "�������� ������:\n";
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "���������� �������� � ������������ ������ �� ���������� �������: ";
	cout << endl;
	cout << "������� ����������� ��������: "; cin >> value;
	cout << "������� ������: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	cout << "�������� ���������� �������� �������: ";
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "�������� ������� �������� �������: ";
	/*arr = pop_front(arr, n);
	Print(arr, n);*/
	Print(arr = pop_front(arr, n), n);
	cout << endl;

	cout << "�������� �������� � ������������ ������� �� ���������� �������: ";
	cout << endl;
	cout << "������� ������: "; cin >> index;
	cout << "������ ����� �������� �������� �� �������: ";
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
}
template<typename T>
void FillRand(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//����� ���������� ���������� � �������� �������������:
		*(arr + i) = rand() % 100;
	}
}
template<typename T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//[] - �������� �������������� (subscript operator)
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>
T* push_back(T arr[], int& n, int value)
{
	//1) ������� �������� ������:
	T* buffer = new T[n + 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		//�������� ���������� ��������������:
		buffer[i] = arr[i];
	}
	//3) �������� �������� ������:
	delete[] arr;
	//4) ��������� ����� ��������� �������, ������� ������ �������:
	arr = buffer;
	//������ ������ � ������ arr ����� ��������� ��������, ��������� ��� ���������
	//������ ��� ������ ��������.

	//5) ��������� �������� � ����� �������
	arr[n] = value;
	//6) ����� ���� ��� � ������� ��������� �������, ���������� ��� ��������� ������������� �� 1
	n++;
	//		Mission complete!
	return arr;
}
template<typename T>
T* push_front(T arr[], int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
		//�������� ���������� �� ��������� �� 1 ������� ������:
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
template<typename T>
T* insert(T arr[], int& n, int value, int& index)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
		buffer[index] = value;
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
	
}
template<typename T>
T* pop_back(T arr[], int& n)
{
	T* buffer = new T[n - 1]{};
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T>
T* pop_front(T arr[], int& n)
{
	//T* buffer = new int[n - 1]{};
	T* buffer = new T[--n]{};
	for (int i = 0; i < n; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	/*arr = buffer;
	return arr;*/
	return buffer;
}
template<typename T>
T* erase(T arr[], int& n, int& index)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}