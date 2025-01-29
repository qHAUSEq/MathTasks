#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");

	double x, y;
	int N, okpoints = 0;
	std::cout << "Введите кол-во точек: "; 
	std::cin >> N;
	while (N <= 0 || std::cin.fail())
	{
		system("cls");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Введите кол-во точек: ";
		std::cin >> N;
	}
	std::cout << std::endl;

	for (size_t i = 0; i < N; ++i) {
		std::cout << "Введите координаты x, y: ";
		std::cin >> x >> y;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Введите координаты x, y: ";
			std::cin >> x >> y;
		}

		double topYp = x >= 0 ? 1 - x + 1 : x + 2;
		double topYm = topYp * (-1);
		bool flagX = x <= 1 && x >= -1;
		bool flagY = y <= topYp && y >= topYm;

		if (flagX && flagY) {
			std::cout << "Точка попала в область." << std::endl;
			okpoints++;
		} else {
			std::cout << "Точка не попала в область по координате: ";
			if (!flagX) std::cout << " X ";
			if (!flagY) std::cout << " Y " << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "Количество точек, которые попали в область: " << okpoints << std::endl;
	if (okpoints == N) std::cout << "Все точки попали в область." << std::endl;
	if (okpoints < N) std::cout << "Часть точек попала, часть нет." << std::endl;

	return 0;
}