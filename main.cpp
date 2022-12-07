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
    if(argc!=4){exit(0);}
    string path = argv[2];
    IsValidPath(path);
    Distance *distance1 = GetDistanceFun(whatDistance(argv[3]));
    vector<double> gg;
    if(!IsValidK(argv[1])) {
        cout<<"the K invalid!"<<endl;
        exit(0);
    }
    int k= stoi(argv[1]);
    if(k<=0){exit(0);}
    gg = MakeVector();
    ClassifiedArray x= ClassifiedArray(argv[2],gg,k,distance1);
    cout << x.KNN() <<endl;
}


