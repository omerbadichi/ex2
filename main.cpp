//
// Created by omer on 12/4/22.
//
#include "Tools.h"
# include <string>
#include <iostream>
#include "ClassifiedArray.h"
#include "Distance.h"
#include "ManhattanDistance.h"
#include <cmath>
using namespace std;
bool IsValidK(const string& s){
    for(char i : s){
        if(!isdigit(i))
            return false;
    }
    return true;
}
int main(int argc,char* argv[]){
    vector<double> gg;
    gg = MakeVector();
    Distance *distance1 = GetDistanceFun(argv[3]);
    if(!IsValidK(argv[1]))
        exit(0);
    ClassifiedArray x= ClassifiedArray(argv[2],gg,3,distance1);
    x.KNN();
    cout<<x.FindClassificition();
    }
