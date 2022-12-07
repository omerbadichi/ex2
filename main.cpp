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
    if(!IsValidK(argv[1])) {
        cout<<"the K invalid!"<<endl;
        exit(0);
    }
    int k= stoi(argv[1]);
    if(k<=0){
        cout<<"invalid k"<<endl;
        exit(0);}
    string path = argv[2];
    Distance *distance1 = GetDistanceFun(whatDistance(argv[3]));
    vector<double> gg;
    ClassifiedArray x= ClassifiedArray(argv[2],gg,k,distance1);
    x.PopulateVector();
    while (true) {
        gg = MakeVector();
        x.SetVectorToCompare(gg);
        cout << x.KNN() << endl;
    }
}


