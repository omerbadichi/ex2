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
#include <algorithm>
#include <map>
using namespace std;
class ClassifiedArray {
private:
    vector<NameVector> vectors;
    Distance *distance;
    string path;
    vector<double> ToCompare;
    int k;

public:
    ClassifiedArray(string path, vector<double> ToCompare, int k, Distance *distance1);
    void PopulateVector();
    std::vector<NameVector> GetVectors();
    string GetPath();
    void SetPath (string NewPath);

    int GetK();
    void SetK (int k);

    void SortByValue();
    void PopulateDistance ();



    string FindClassification();

    void KNN ();

};


#endif //EX2_CLASSIFIEDARRAY_H
