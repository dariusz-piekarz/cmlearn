#pragma once

#include <iostream>
#include <functional>
#include <vector>



#include "lin_alg.hpp"


using namespace std;


vector<double> gradient_descent(function<double(const vector<double>&)> fn, const vector<double> & starting_point, double threshold = 1e-6, double learning_rate = 1e-3, size_t max_iter = 1e7, double dt = 1e-5)
{
    vector<double> point(starting_point);
    vector<double> new_point(starting_point);
    vector<double> incremental_point(starting_point.size());
    vector<double> convergent_point(starting_point.size());

    for (size_t i = 0; i < max_iter; i++)
    {
        for (int j = 0; j < point.size(); j++)
        {
            incremental_point = point;
            incremental_point[j] = point[j] + dt;
            new_point[j] = point[j] - learning_rate * (fn(incremental_point) - fn(point)) / dt;
            convergent_point[j] = new_point[j] - point[j];
        }


        if (norm(convergent_point) < threshold)
            break;
        point = new_point;
    }

    return point;
};


vector<double> grad_dsc(function<double(const vector<double>&)> fn, const vector<double>& starting_point, function<double(double)> learning_rate, double threshold = 1e-6, size_t max_iter = 1e7, double dt = 1e-5)
{
    vector<double> point(starting_point);
    vector<double> new_point(starting_point);
    vector<double> incremental_point(starting_point.size());
    vector<double> convergent_point(starting_point.size());

    for (size_t i = 0; i < max_iter; i++)
    {
        for (int j = 0; j < point.size(); j++)
        {
            incremental_point = point;
            incremental_point[j] = point[j] + dt;
            new_point[j] = point[j] - learning_rate(static_cast<double>(j)) * (fn(incremental_point) - fn(point)) / dt;
            convergent_point[j] = new_point[j] - point[j];
        }


        if (norm(convergent_point) < threshold)
            break;
        point = new_point;
    }

    return point;
};