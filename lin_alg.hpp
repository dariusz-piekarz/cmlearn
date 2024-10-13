#pragma once


#include <iostream>
#include <vector>
#include <math.h>
#include <ranges>


using namespace std;


double norm(const vector<double>& v, const double p=2.0)
{
	double norm = 0.0;
	ranges::for_each(v, [&norm, p](double x) {norm += pow(abs(x), p); });
	return pow(norm, 1.0 / p);
}

template<typename T = double>
double mean(const vector<T>& v)
{
	double sum = 0.0;
	ranges::for_each(v, [&sum](T x) {sum += static_cast<double>(x); });
	return sum / v.size();
}

template<typename T = double>
double harmonic(const vector<T>& v)
{
	double sum = 0.0;
	ranges::for_each(v, [&sum](T x) {sum += 1 / static_cast<double>(x); });
	return v.size() / sum;
}

template<typename T = double>
double geometric(const vector<T>& v)
{
	double prod = 1.0;
	ranges::for_each(v, [&prod](T x) {prod *= static_cast<double>(x); });
	return pow(prod, 1 / v.size());
}

template<typename T = double>
double stdev(const vector<T>& v, const double & mean_val, const double p=2.0)
{
	double sum = 0.0;
	ranges::for_each(v, [&sum](T x) {sum += pow(abs(static_cast<double>(x) - mean_val), p); });

	return pow(sum / v.size(), 1.0 / p);
}

template<typename T = double>
double p_error(const vector<T>& v, const vector<T>& w, const double p = 2.0)
{
	if (v.size() != w.size())
		throw length_error("'v' and 'w' must have the same size!");

	double sum = 0.0;
	ranges::for_each(v, w, [&sum](T x, T y) {sum += pow(abs(static_cast<double>(x) - static_cast<double>(y)), p); });

	return pow(sum / v.size(), 1.0 / p);
}