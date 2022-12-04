//
// Created by omer on 12/4/22.
//

#ifndef EX2_DISTANCE_H
#define EX2_DISTANCE_H
# include <vector>
# include <cmath>
# include <string>
#include <iostream>
using namespace std;

class Distance {
    double manhattan(vector<double> v1, vector<double> v2);
    double chebyshev(vector<double> v1, vector<double> v2);
    double canberra(vector<double> v1, vector<double> v2);
    double minkowski(vector<double> v1, vector<double> v2,double p=2);
    double euclidean(vector<double> v1, vector<double> v2);
};


#endif //EX2_DISTANCE_H
