#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, int value);
int* push_front(int* arr, int& n, int value);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n]; //���������� ������������� �������

	FillRand(arr, n);
	cout << "�������� ������:\n";
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	//arr = push_front(arr, n, value);
	Print(arr = push_front(arr, n, value), n);

	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//����� ���������� ���������� � �������� �������������:
		*(arr + i) = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//[] - �������� �������������� (subscript operator)
		cout << arr[i] << "\t";
	}
	cout << endl;
}
int* push_back(int arr[], int& n, int value)
{
	//1) ������� ��������� ������:
	int* buffer = new int[n + 1]{};

	//2) �������� ��� �������� �� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
	//�������� ���������� �������������:
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������:
	delete[] arr;

	//4) ��������� ������ ��������� ������� ������� ������ �������:
	arr = buffer;
	//������ ������ � ������ arr ����� ��������� ��������, 
	// ��������� ��� ��������� ������ ��� ������ ��������

	//5) ��������� �������� � ����� �������
	arr[n] = value;

	//6) ����� ���� ��� � ������� ��������� �������, ���������� ��� ��������� ������������� �� 1
	n++;
	// Mission complete!  
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1]{};
	//�������� ���������� �� ��������� �� 1 ������� ������:
	for (int i = 0; i < n; i++) buffer[i + 1] = arr[i];
	
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}