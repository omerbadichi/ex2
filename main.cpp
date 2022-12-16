//
// Created by omer on 12/4/22.
//
#include "Tools.h"
# include <string>
#include <iostream>
#include "ClassifiedArray.h"
#include "Distance.h"
#include <cmath>
#include <stdexcept>

/**
 * run the program.
 */
using namespace std;
int main(int argc,char* argv[]){
    if(argc!=4){
        cout<<"not enough arguments to run the program"<<endl;
        exit(0);}
    if(!IsValidK(argv[1])) {
        cout<<"the K is invalid!"<<endl;
        exit(0);
    }
    int k= stoi(argv[1]);
    if(k<=0){
        cout<<"the K is invalid!"<<endl;
        exit(0);}
    string path = argv[2];
    Distance *distance1 = GetDistanceFun(whatDistance(argv[3]));
    vector<double> vec;
    ClassifiedArray x= ClassifiedArray(argv[2],vec,k,distance1);
    x.PopulateVector();
    if(k>x.GetVectors().size())
    {
        cout<<"the K is invalid!"<<endl;
        exit(0);

    }
    while (true) {
        try {
            cout<<"enter a vector"<<endl;
            vec = MakeVector();
            x.SetVectorToCompare(vec);
            cout << x.KNN() << endl;
        }catch (invalid_argument &e)
        {
            cout << "the vector is invalid!" << endl;
        }
    }
}



