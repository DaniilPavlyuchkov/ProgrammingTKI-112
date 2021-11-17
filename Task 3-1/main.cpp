#include <iostream>
#include <cmath> 
#include <iomanip>

/**
 * \brief ������������ �������� ������� � �������� �����
 * \param x �������� �����
 * \return ���������� �������� ������� � �������� �����
 */
double myFunc(double x);

/**
 * \brief ���������, ���������� �� ������� � �������� �����
 * \param x �������� �����
 * \return ���������� true, ���� �������� ������� � �������� ����� ����������
 */
bool isCalculated(double x);


int main()
{
	const double X_START = 1;
	const double X_FINISH = 3;
	const double STEP = 0.2;
	double x = X_START;

	while (x <= X_FINISH)
	{
		if (isCalculated(x))
		{
			const double y = myFunc(x);
			std::cout << "x = " << std::setw(5) << std::left << std::setprecision(5) << x << " y = " << y << "\n";
		}
		else
		{
			std::cout << "x = " << x << " y = �� ����������" << "\n";
		}

		x += STEP;
	}


	return 0;
}

double myFunc(const double x)
{
	return 3 * log(x) * log(x) + 6 * log(x) - 5;
}

bool isCalculated(const double x)
{
	return x > 0;
}