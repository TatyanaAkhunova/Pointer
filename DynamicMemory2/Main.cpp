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

	cout << "Удаление последнего элемента массива: ";
	Print(arr = pop_back(arr, n), n);
	cout << "Удаление первого элемента массива: ";
	Print(arr = pop_front(arr, n), n);

	delete[] arr;
#endif // 

	int rows; //количество строк
	int	cols;  //количество элементов строки 
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	//Объявление двумерного динамического массива:
	int** arr = Allocate(rows, cols);
	/*int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}*/
	// Использование двумерного динамического массива:
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_down(arr, rows, cols);
	Print(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	push_col_right(arr, rows, cols);
	Print(arr, rows, cols);

	//Удаление двумерного динамического массива:
	Clear(arr, rows);
	cout << arr;
	/*for (int i = 0; i < rows; i++)
	{
		delete[] arr[i]; //Удаляем строки
	}
	delete[] arr; //Удаляем массив указателей*/


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
		delete[] arr[i]; //Удаляем строки
	}
	delete[] arr; //Удаляем массив указателей
	arr = nullptr; //Оператор delete[] принимает указатель arr, и удаляет память по адресу
	// в этом указателе, при этом адрес хранящийся в указателе arr НЕ изменяется
	// и вполне возможна ситуация, когда к массиву обратятся после его удаления,
	// что приведет к ошибке на этапе выполнения и аварийному завершению программы
	// Для того, чтобы избежать таких ситуаций, указатели лучше заннулять после удаления
	// и при каждом обращении к массиву проверять массив на nullptr.
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и оператор разыменования:
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
		//[] - оператор индексирования (subscript operator)
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
	//1) Создаем буферный массив указателей:
	int** buffer = new int*[rows + 1]{};
	//2) Копируем адреса строк из исходного массива указателей в буферный
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив:
	delete[] arr;
	//4) Подменяем адрес старого массива адресом нового массива:
	arr = buffer;
	//5) Создаем добавляемую строку:
	arr[rows] = new int[cols] {};
	//6) После добавления строки, количество строк массива увеличивается на одну:
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
