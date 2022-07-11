#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

template<typename T>
int** Allocate(const int rows, const int cols);
void Clear(int**& arr, const int rows);//очистка памяти 0000000

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);//заполнение случайными числами
void FillRand(int** arr, const int rows, const int cols);//заполнение двумерного массива случайными числами
void Print(int arr[], const int n);//вывод массива в консоль
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);//добавляет указанное значение в конец одномерного динамического массива
int* push_front(int* arr, int& n, int value);//добавляет указанное значение в начало одномерного динамического массива
int* insert(int* arr, int& n, int value, int& index);//вставляет указанное значение в динамический массив по указанному индексу
int* pop_back(int* arr, int& n);//удаляет последний элемент массива
int* pop_front(int* arr, int& n);//удаляет первый элемент массива
int* erase(int* arr, int& n, int& index);//удаляет указанное значение в динамическом массиве по указанному индексу

int** push_row_down(int** arr, int& rows, const int cols);//добавление строки вниз двумерного динамического массива
int** push_row_up(int** arr, int& rows, const int cols); //добавление строки вверх двумерного динамического массива
void insert_row(int**& arr, int& rows, const int cols, int index);//добавление строки по указанному индексу
void push_col_right(int** arr, const int rows, int& cols);//добавление столбца справа
void push_col_left(int** arr, const int rows, int& cols);//добавление столбца слева
void insert_col(int**& arr, const int rows, int& cols, int index);//добавление столбца по указанному индексу

//void pop_row_doun(int**& arr, int& rows, const int cols);//удаление нижней строки
int** pop_row_doun(int** arr, int& rows, const int cols);//
void pop_row_up(int**& arr, int& rows, const int cols);//удаление верхней строки

void pop_col_right(int** arr, const int rows, int& cols);//удаление столбца справа
void pop_col_left(int** arr, const int rows, int& cols);//удаление столбца слева
void erase_col(int**& arr, const int rows, int& cols, int index);//удаление столбца по указанному индексу
void erase_row(int**& arr, int& rows, const int cols, int index); // удаление строки по указанному индексу


//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2
//#define DYNAMIC_MEMORY_3
#define DYNAMIC_MEMORY_4

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
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
	//arr = push_front(arr, n, value);
	Print(arr = push_front(arr, n, value), n);
	Print(arr = pop_back(arr, n), n);
	Print(arr = pop_front(arr, n), n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows;	//количество строк
	int cols;	//количество элементов строки
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	//Объявление двумерного динамического массива:
	int** arr = Allocate(rows, cols);

	//Использование двумерного динамического массива:
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_down(arr, rows, cols);
	Print(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	push_col_right(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);
	cout << arr << endl;
#endif // DYNAMIC_MEMORY_2

#ifdef DYNAMIC_MEMORY_3
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	cout << "Исходный массив:\n";
	Print(arr, n);

	int even_size = 0;
	int	odd_size = 0;

	for (int i = 0; i < n; i++)
	{
		arr[i] % 2 == 0 ? even_size++ : odd_size++;
	}
	cout << "Количество четных элементов: " << even_size << endl;
	cout << "Количество нечетных элементов: " << odd_size << endl;

	int* even_arr = new int[even_size] {};
	int* odd_arr = new int[odd_size] {};

	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		(arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];
	}
	cout << "Массив с четными элементами:\n"; Print(even_arr, even_size);
	cout << "Массив с нечетными элементами:\n"; Print(odd_arr, odd_size);

	delete[] odd_arr;
	delete[] even_arr;

	int value;
	cout << "Введите добавляемое значение в конец динамического массива: "; cin >> value;
	Print(arr = push_back(arr, n, value), n);

	cout << "Введите добавляемое значение в начало динамического массива: "; cin >> value;
	Print(arr = push_front(arr, n, value), n);

	int index;
	cout << "Добавление значения в динамический массив по указанному индексу: ";
	cout << endl;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс: "; cin >> index;
	Print(arr = insert(arr, n, value, index), n);

	cout << "Удаление последнего элемента массива: ";
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "Удаление первого элемента массива: ";
	Print(arr = pop_front(arr, n), n);

	cout << "Удаление значения в динамическом массиве по указанному индексу: ";
	cout << endl;
	cout << "Введите индекс: "; cin >> index;
	cout << "Массив после удаления значения по индексу: ";
	Print(arr = erase(arr, n, index), n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_3

	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавление строки в конец массива: "; cout << endl; 
	arr = push_row_down(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавление строки в начало массива: "; cout << endl;
	arr = push_row_up(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавление строки в динамический массив по указанному индексу: ";
	cout << endl;
	int index;
	cout << "Введите индекс: "; cin >> index;
	insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Добавление столбца справа: "; cout << endl;
	push_col_right(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавление столбца слева: "; cout << endl;
	push_col_left(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавление столбца в динамический массив по указанному индексу: ";
	cout << endl;
	cout << "Введите индекс: "; cin >> index;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Удаление последней строки: "; cout << endl;
	//pop_row_doun(arr, rows, cols);
	arr = pop_row_doun(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаление верхней строки: "; cout << endl;
	pop_row_up(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаление столбца слева: "; cout << endl;
	pop_col_left(arr, rows, cols);
	Print(arr, rows, cols);

    cout << "Удаление столбца справа: "; cout << endl;
	pop_col_right(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаление столбца в динамическом массиве по указанному индексу: ";
	cout << endl;
	cout << "Введите индекс: "; cin >> index;
	erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Удаление строки в динамическом массиве по указанному индексу: ";
	cout << endl;
	cout << "Введите индекс: "; cin >> index;
	erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	Clear(arr, rows);
	cout << arr;

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
	//Удаление двумерного динамического массива:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];	//удаляем строки
	}
	delete[] arr;	//удаляем массив указателей
	arr = nullptr;	
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и оператор разыменования:
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
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
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}
int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* insert(int* arr, int& n, int value, int& index)
{
	int* buffer = new int[n + 1]{};
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
int* pop_back(int* arr, int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int* arr, int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int* erase(int* arr, int& n, int& index)
{
	int* buffer = new int[--n]{};
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
int** push_row_down(int** arr, int& rows, const int cols)
{
	//1) Создаем буферный массив указателей:
	int** buffer = new int* [rows + 1]{};
	//2) Копируем адреса строк из исходного массива указателей в буферный:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удавляем исходный массив:
	delete[] arr;
	//4) Подменяем адрес старого массива адресом нового массива:
	arr = buffer;
	//5) Создаем добавляемую строку:
	arr[rows] = new int[cols] {};
	//6) После добавления строки, количество строк массива увеличивается на одну:
	rows++;
	return arr;
}
int** push_row_up(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new int[cols] {};
	rows++;
	return arr;
}
void insert_row(int**& arr, int& rows, const int cols, int index)
{
	if (index > rows) return;
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < index; i++) buffer[i] = arr[i];
	for (int i = index; i < rows; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = new int[cols]{};
	rows++;
}
void push_col_right(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void push_col_left(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++) buffer[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void insert_col(int**& arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++) buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
/*void pop_row_doun(int**& arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr[rows];
	delete[] arr;
	arr = buffer;
}*/
int** pop_row_doun(int** arr, int& rows, const int cols)
{
	delete[] arr[rows-1];
	int** buffer = new int* [--rows] {};
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}

void pop_row_up(int**& arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i+1];
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
}
void pop_col_right(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [cols-1]{};
		for (int j = 0; j < cols-1; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void pop_col_left(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void erase_col(int**& arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [cols - 1]{};
		for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++) buffer[j-1] = arr[i][j];
		delete[] arr[i];
		arr [i] = buffer;
	} cols--;
	
}
void erase_row(int**& arr, int& rows, const int cols, int index)
{
	int** buffer = new int* [rows-1];
	for (int i = 0; i < index; i++) buffer[i] = arr[i];
	buffer[index] = new int[cols] {};
	for (int i = index; i < rows; i++) buffer[i-1] = arr[i];
	delete[] arr;
	arr = buffer;
	rows--;
}
