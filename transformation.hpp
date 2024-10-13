#pragma once

#include <iostream>
#include <vector>
#include <ranges>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;


vector<double> min_max(vector<double>& data)
{
	double min_val = *min_element(data.begin(), data.end());
	double max_val = *max_element(data.begin(), data.end());
	vector<double> results;
	ranges::for_each(data, [&results, &min_val, &max_val](double v) {results.push_back((v - min_val) / (max_val - min_val)); });
	return results;
}
