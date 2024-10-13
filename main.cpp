#include <iostream>
#include <math.h>
#include <vector>
#include <ranges>
#include <functional>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>


#include "cmlearn.hpp"


using namespace std;
namespace py = pybind11;

double learning_rate_fn(double t)
{
    return pow(0.1,t+3);
}

double sample_function(const vector<double>& v)
{
	double x = v[0];
	double y = v[1];
	return pow(1 - x, 2) + 100 * pow(y - x * x, 2);
}


int main(void)
{
    // Punkt startowy
    const vector<double> starting_point = { -1.2, 1.0 };

    // Parametry algorytmu gradientu
    double threshold = 1e-6;
    double learning_rate = 0.001;
    double dt = 1e-5;
    size_t max_iter = 10000000;

    // Wywo³anie algorytmu gradientu
    vector<double> result = gradient_descent(sample_function, starting_point, threshold, learning_rate, max_iter, dt);
    vector<double> result1 = grad_dsc(sample_function, starting_point, learning_rate_fn, threshold,  max_iter, dt);

    // Wyœwietlenie wyniku
    cout << "Min = (" << result[0] << ", " << result[1] << ")" << endl;
    cout << "Min = (" << result1[0] << ", " << result1[1] << ")" << endl;
    vector<double> v = { 1, 2, 3, 4, -5 };
    vector<double> w = min_max(v);
	for (int i = 0; i < w.size(); i++)
		cout << w[i] << endl;
	return 0;
}
