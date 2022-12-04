//
// Created by omer on 12/4/22.
//

#ifndef EX2_CLASSIFIEDARRAY_H
# include <vector>
# include <cmath>
# include <string>
#include <iostream>
#include "Distance.h"
#include "NameVector.h"
using namespace std;
class ClassifiedArray {
private:
    vector<vector<NameVector>> vectors;
    Distance distance;
    string path;

public:
    bool IsValidDouble(const string& s);
    vector<double> GetVector();
    bool ValidVectors(const vector<double>& v1, const vector<double>& v2);

};


#endif //EX2_CLASSIFIEDARRAY_H
