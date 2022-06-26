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
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Добавление значения в динамический массив по указанному индексу: ";
	cout << endl;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	cout << "Удаление последнего элемента массива: ";
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "Удаление первого элемента массива: ";
	/*arr = pop_front(arr, n);
	Print(arr, n);*/
	Print(arr = pop_front(arr, n), n);
	cout << endl;

	cout << "Удаление значения в динамическом массиве по указанному индексу: ";
	cout << endl;
	cout << "Введите индекс: "; cin >> index;
	cout << "Массив после удаления значения по индексу: ";
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
}
template<typename T>
void FillRand(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и оператор разыменования:
		*(arr + i) = rand() % 100;
	}
}
template<typename T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//[] - оператор индексирования (subscript operator)
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>
T* push_back(T arr[], int& n, int value)
{
	//1) Создаем буферный массив:
	T* buffer = new T[n + 1]{};
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
template<typename T>
T* push_front(T arr[], int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
		//Элементы копируются со смещением на 1 элемент вправо:
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