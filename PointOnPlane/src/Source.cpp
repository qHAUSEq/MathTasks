#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");

	double x, y;
	int N, okpoints = 0;
	std::cout << "������� ���-�� �����: "; 
	std::cin >> N;
	while (N <= 0 || std::cin.fail())
	{
		system("cls");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "������� ���-�� �����: ";
		std::cin >> N;
	}
	std::cout << std::endl;

	for (size_t i = 0; i < N; ++i) {
		std::cout << "������� ���������� x, y: ";
		std::cin >> x >> y;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "������� ���������� x, y: ";
			std::cin >> x >> y;
		}

		double topYp = x >= 0 ? 1 - x + 1 : x + 2;
		double topYm = topYp * (-1);
		bool flagX = x <= 1 && x >= -1;
		bool flagY = y <= topYp && y >= topYm;

		if (flagX && flagY) {
			std::cout << "����� ������ � �������." << std::endl;
			okpoints++;
		} else {
			std::cout << "����� �� ������ � ������� �� ����������: ";
			if (!flagX) std::cout << " X ";
			if (!flagY) std::cout << " Y " << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "���������� �����, ������� ������ � �������: " << okpoints << std::endl;
	if (okpoints == N) std::cout << "��� ����� ������ � �������." << std::endl;
	if (okpoints < N) std::cout << "����� ����� ������, ����� ���." << std::endl;

	return 0;
}