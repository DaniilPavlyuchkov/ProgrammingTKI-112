#include <iostream>

size_t get_sequence_size()

/**
 * \brief ������������ �������� ������������� ����� � ����������� �� �������.
 * \param index ������, ����� ��������.
 * \return ���������� 0 � ������ ������.
 */
double get_recurrent_member(const size_t index);

/**
 * \brief ����� ����� � ���������.
 * \return ���������� 0 � ������ ������.
 */
int main()
{
	std::cout << "������� ���������� ������ ������������������";
	int count;
	std::cin >> count;
	if (count < 0)
		throw std::invalid_argument("�������� ������ ���� ������ 0");

	const size_t n = count;

	return 0;
}

double get_recurrent_member(const size_t index)
{

}