//
// Created by omer on 12/4/22.
//
# include <string>
#include <iostream>
#include "ClassifiedArray.h"
#include "Distance.h"
#include "Tools.h"
using namespace std;
int main(int argc,char* argv[]){
    vector<double> gg;
    gg = MakeVector();
    Distance *distance1 = GetDistanceFun(argv[3]);
    ClassifiedArray x= ClassifiedArray(argv[2],gg,3,distance1);
    x.KNN();
    int i=0;
    while(x.GetVectors().size()>i) {
        cout<<x.GetVectors().at(i).GetDistanceFromVector()<<endl;
        i++;
    }
    cout<<i;
    }
