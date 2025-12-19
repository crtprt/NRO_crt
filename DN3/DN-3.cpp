#include <iostream>
#include <cmath>
#include <iomanip>

double calcAtan(double* x, int* N_steps)
{
    double xx1 = *x;
    int N = *N_steps;
    if (N <= 0) return 0.0;

	// Taylorjeva vrsta za arctan(x)
    double term = xx1;
    double sum = term / 1.0;
    for (int k = 1; k < N; ++k) {
        term *= -(xx1 * xx1);
        sum += term / (2.0 * k + 1.0);
    }
    return sum;
}

int main()
{
	// Definicija meja integrala
    const double a = 0.0;
    const double PI = std::acos(-1.0);
    const double b = PI / 4.0;

	// Vnos stevila podintervalov in clenov Taylorjeve vrste
    int n_intervals;
    int tayl_terms;
    std::cout << "Vnesi stevilo trapeznih podintervalov: ";
    std::cin >> n_intervals;
    std::cout << "Vnesi stevilo clenov Taylorjeve vrste: ";
    std::cin >> tayl_terms;


    double h = (b - a) / n_intervals;
    auto f = [&](double x)->double {
        double arg = x / 2.0;
        double arg_copy = arg;
        int Ncopy = tayl_terms;
        double at = calcAtan(&arg_copy, &Ncopy);
        return std::exp(3.0 * x) * at;
        };

	// Formula za trapezno pravilo
    double sum = f(a) + f(b);
    for (int i = 1; i < n_intervals; ++i) {
        double xi = a + i * h;
        sum += 2.0 * f(xi);
    }

    double integral = (h / 2.0) * sum;


    std::cout << std::fixed << std::setprecision(12);
    std::cout << "\nOcena integrala = " << integral << "\n";
    return 0;

}