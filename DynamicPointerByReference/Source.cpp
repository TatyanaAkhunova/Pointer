#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, int value);
void push_front(int*& arr, int& n, int value);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	cout << "Исходный массив:\n";
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	push_front(arr, n, value);
	Print(arr, n);

	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и оператор разыменования:
		*(arr + i) = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//[] - оператор индексирования (subscript operator)
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value)
{
	//1) Создаем буферный массив:
	int* buffer = new int[n + 1]{};
	//2) Копируем все элементы из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		//Элементы копируются соответственно:
		buffer[i] = arr[i];
	}
	//3) Удавляем исходный массив:
	delete[] arr;
	//4) Подменяем адрес исходного массива, адресом нового массива:
	arr = buffer;
	//Только теперь в массив arr можно добавлять значение, поскольку там появилася
	//ячейка для нового значения.

	//5) Добавляем значение в конец массива
	arr[n] = value;
	//6) После того как в массиве добавился элемент, количество его элементов увеличивается на 1
	n++;
	//		Mission complete!
	return arr;
}

void push_front(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
		//Элементы копируются со смещением на 1 элемент вправо:
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}