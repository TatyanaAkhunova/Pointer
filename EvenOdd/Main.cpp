#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	cout << "�������� ������:\n";
	Print(arr, n);

	//1) ������� ���������� ������ � �������� �������� � �������� �������
	int even_size = 0; //���������� ������ �������� � �������
	int	odd_size = 0; //���������� �������� �������� � �������

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) even_size++;
		else odd_size++;
	}
	cout << "���������� ������ ���������: " << even_size << endl;
	cout << "���������� �������� ���������: " << odd_size << endl;

	//�������� ������ ��� ������ � �������� ���������:
	int* even_arr = new int[even_size] {};
	int* odd_arr = new int[odd_size] {};
	//{} - �������������� ������, ���������� ���������� new,
	//�.�. ��������� �� ��������� �� ���������, ��� int - ��� 0

	//�������� ������ � �������� �������� � ��������������� �������
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		/*if (arr[i] % 2 == 0)
			even_arr[j++] = arr[i];
			//j++;
		else
			odd_arr[k++] = arr[i];
			//k++;*/
		(arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];
	}

	//4) ������� ������� �� �����:
	cout << "������ � ������� ����������:\n"; Print(even_arr, even_size);
	cout << "������ � ��������� ����������:\n"; Print(odd_arr, odd_size);

	//�������� delete[] ����������� ������, ���������� ��������, � ���������� ��� ������
	//������� ��
	delete[] odd_arr;
	delete[] even_arr;
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	} cout << endl;
}