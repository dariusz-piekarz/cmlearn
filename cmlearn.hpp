#pragma once

#include <iostream>
#include <functional>
#include <vector>


#include "lin_alg.hpp"
#include "gradient.hpp"
#include "linearmodel.hpp"
#include "transformation.hpp"


using namespace std;


double norm(const vector<double>&, double);

template<typename T = double>
double mean(const vector<T>&);
template<typename T = double>
double stdev(const vector<T>&, const double&, const double);

vector<double> gradient_descent(function<double(const vector<double>&)>, const vector<double>&, double, double, size_t, double);
vector<double> grad_dsc(function<double(const vector<double>&)>, const vector<double>&, double, function<double(double)>, size_t, double);

vector<double> min_max(vector<double>&);