#include <iostream>

using namespace std;

/**
 * \brief Функция для нахождения текущего элемента.
 * \param k Переменная элемента ряда.
 * \return Возвращает значение текущего элемента.
**/
double getCurrentNum(int k);

/**
 * \brief Функция для вычисления суммы первых n элементов ряда.
 * \param n Количество элементов ряда.
 * \param k Переменная элемента ряда.
 * \return Возвращает сумму первых n элементов ряда.
 **/
double getSumN(int k, int n);

/**
 *\brief Функция для вычисления суммы членов ряда не меньших числа e.
 *\param e Заданное число.
 *\param k Переменная элемента ряда.
 *\return Возвращает сумму членов ряда не меньших числа e.
**/
double getSumE(int k, double e);

/**
 * \brief Точка входа в программу
 * \return В случае успеха возвращает 0
 */
int main()
{
	int k = 1;
	int n;
	double e = 0.0;

	cout << "Введите количество членов ряда: ";
	cin >> n;
	cout << "\nВведите значение e: ";
	cin >> e;

	cout << "\nСумма первых n членов: " << getSumN(k, n);
	cout << "\nСумма членов не меньших числа е: " << getSumE(k, e) << endl;

	return 0;
}

double getCurrentNum(const int k)
{
	return (pow(-1, k)) / (2 * k);
}

double getSumN(int k, int n)
{
	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += getCurrentNum(k);
		k++;
	}

	return sum;
}

double getSumE(int k, double e)
{
	double sum = 0;
	double current = getCurrentNum(k);

	while (current > e)
	{
		sum += current;
		k++;
		current = getCurrentNum(k);
	}

	return sum;
}