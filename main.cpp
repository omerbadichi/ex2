//
// Created by omer on 12/4/22.
//
#include "Tools.h"
# include <string>
#include <iostream>
#include "ClassifiedArray.h"
#include "Distance.h"
#include <cmath>
using namespace std;
int main(int argc,char* argv[]){
    vector<double> gg;
    gg = MakeVector();
    Distance *distance1 = GetDistanceFun(argv[3]);
    if(!IsValidK(argv[1]))
        exit(0);
    ClassifiedArray x= ClassifiedArray(argv[2],gg,3,distance1);
    cout << x.KNN() <<endl;
}

