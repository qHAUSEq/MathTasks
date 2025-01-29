#include <iostream>
#include <cmath>

double eps = 0.001;

constexpr static int factorial(int n)
{
    int f = 1;
    for (size_t i = 2; i <= n; ++i) {
        f *= i;
    }
    return f;
}

static double Y(double x)
{
    return (std::exp(x) + std::exp(-x) + (2 * std::cos(x))) / 4 - 1;
}

static double S(double x)
{
    int max_iter = 100;
    double first = std::pow(x, 4) / factorial(4);
    double sum = first;
    for (size_t n = 2; std::fabs(first) > eps; ++n) {
        first = std::pow(x, 4 * n) / factorial(4 * n);
        sum += first;
        if (n > max_iter) {
            sum = 0;
            break;
        }
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "ru");

    std::cout << "¬ведите погрешность E: ";

    std::cin >> eps;
    while (eps <= 0 || std::cin.fail())
    {
        system("cls");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "¬ведите погрешность E:   ";
        std::cin >> eps;
    }

    std::cout << "X : \tS(x) : \t\tY(x) :" << std::endl;

    for (double x = 0.5; x <= 0.8; x += 0.05)
    {
        std::cout << x << "\t" << S(x) << "\t" << Y(x) << std::endl;
    }

    return 0;
}