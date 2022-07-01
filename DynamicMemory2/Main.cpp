#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t";

int** Allocate(const int rows, const int cols);
void Clear(int**& arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand=100);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);
int* push_front(int* arr, int& n, int value);
int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);

int** push_row_down(int** arr, int& rows, const int cols);
void push_col_right(int** arr, const int rows, int& cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
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

	cout << "�������� ���������� �������� �������: ";
	Print(arr = pop_back(arr, n), n);
	cout << "�������� ������� �������� �������: ";
	Print(arr = pop_front(arr, n), n);

	delete[] arr;
#endif // 

	int rows; //���������� �����
	int	cols;  //���������� ��������� ������ 
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;

	//���������� ���������� ������������� �������:
	int** arr = Allocate(rows, cols);
	/*int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}*/
	// ������������� ���������� ������������� �������:
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_down(arr, rows, cols);
	Print(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	push_col_right(arr, rows, cols);
	Print(arr, rows, cols);

	//�������� ���������� ������������� �������:
	Clear(arr, rows);
	cout << arr;
	/*for (int i = 0; i < rows; i++)
	{
		delete[] arr[i]; //������� ������
	}
	delete[] arr; //������� ������ ����������*/


}
int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void Clear(int**& arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i]; //������� ������
	}
	delete[] arr; //������� ������ ����������
	arr = nullptr; //�������� delete[] ��������� ��������� arr, � ������� ������ �� ������
	// � ���� ���������, ��� ���� ����� ���������� � ��������� arr �� ����������
	// � ������ �������� ��������, ����� � ������� ��������� ����� ��� ��������,
	// ��� �������� � ������ �� ����� ���������� � ���������� ���������� ���������
	// ��� ����, ����� �������� ����� ��������, ��������� ����� ��������� ����� ��������
	// � ��� ������ ��������� � ������� ��������� ������ �� nullptr.
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//����� ���������� ���������� � �������� �������������:
		*(arr + i) = rand() % (maxRand-minRand)+minRand;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << tab;
		}
		cout << endl;
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
int* pop_back(int* arr, int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int* arr, int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	return buffer;
}
int** push_row_down(int** arr, int& rows, const int cols)
{
	//1) ������� �������� ������ ����������:
	int** buffer = new int*[rows + 1]{};
	//2) �������� ������ ����� �� ��������� ������� ���������� � ��������
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������:
	delete[] arr;
	//4) ��������� ����� ������� ������� ������� ������ �������:
	arr = buffer;
	//5) ������� ����������� ������:
	arr[rows] = new int[cols] {};
	//6) ����� ���������� ������, ���������� ����� ������� ������������� �� ����:
	rows++;
	return arr;
}
void push_col_right(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j-1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
