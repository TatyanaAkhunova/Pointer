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
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n]; //Объявление динамического массива

	FillRand(arr, n);
	cout << "Исходный массив:\n";
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	//arr = push_front(arr, n, value);
	Print(arr = push_front(arr, n, value), n);

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
	//1) Создаем буфферный массив:
	int* buffer = new int[n + 1]{};

	//2) Копируем все элементы из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
	//Элементы копируются соответсвенно:
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив:
	delete[] arr;

	//4) Подменяем адресс исходного массива адресом нового массива:
	arr = buffer;
	//Только теперь в массив arr можно добавлять значение, 
	// поскольку там появилась ячейка для нового значения

	//5) Добавляем значение в конец массива
	arr[n] = value;

	//6) После того как в массиве добавился элемент, количество его элементов увеличивается на 1
	n++;
	// Mission complete!  
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1]{};
	//Элементы копируются со смещением на 1 элемент вправо:
	for (int i = 0; i < n; i++) buffer[i + 1] = arr[i];
	
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}