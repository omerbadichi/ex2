//
// Created by omer on 12/4/22.
//
# include <string>
#include <iostream>
#include "ClassifiedArray.h"
#include "Distance.h"
#include "ManhattanDistance.h"
using namespace std;

bool IsValidDouble(const string& s){
    int i=0;
    bool dot=false;
    if(s.empty())
        return false;
    if(s.at(i)=='-')
        i++;
    for(;i<s.size();i++){
        if(!isdigit(s.at(i))) {
            if (s.at(i) == '.' && !dot)
                dot = true;
            else
                return false;
        }
    }
    return true;
}
vector<double> MakeVector () {
    //initialize the BufferEmpty to not be '\n'.
    char BufferEmpty='a';
    double number;
    string s;
    vector<double> v;
    while (BufferEmpty != '\n') {
        //this line informs to cin to not ignore whitespaces.
        cin.unsetf(ios_base::skipws);
        cin >> s;
        if(IsValidDouble(s)) {
            number= stod(s);
        }
        else{
            vector<double> empty;
            return empty;
        }
        v.push_back(number);
        cin >> BufferEmpty;
    }
    return v;
}
int main(int argc,char* argv[]){
    vector<double> gg;
    gg = MakeVector();
    Distance *distance1 = new ManhattanDistance;
    ClassifiedArray x=ClassifiedArray(argv[2],gg,3,distance1);
    x.PopulateVector();
    x.PopulateDistance();
    x.SortByValue();
    int i=0;
    while(x.GetVectors().size()>i) {
        cout<<x.GetVectors().at(i).GetDistanceFromVector()<<endl;
        i++;
    }
    cout<<i;
    }
