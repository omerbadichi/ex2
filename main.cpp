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
    if(argc!=4){
        exit(0);
    }
    while (true) {
        if (!IsValidK(argv[1]))
            exit(0);
        int k = stoi(argv[1]);
        if(k<=0){
            cout<<"The k isnt valid"<<endl;
            exit(0);
        }
        vector<double> gg;
        gg = MakeVector();
        Distance *distance1 = GetDistanceFun(argv[3]);
        ClassifiedArray x = ClassifiedArray(argv[2], gg, k, distance1);
        cout << x.KNN() << endl;
    }
}


