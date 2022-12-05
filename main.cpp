//
// Created by omer on 12/4/22.
//
# include <string>
#include <iostream>
#include "ClassifiedArray.h"
using namespace std;
bool IsValidDouble(const string& s);
vector<double>  MakeVector () {
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
int main(int argc,char* argv[]){
    vector<double> vl;
    vl=MakeVector();
    ClassifiedArray x=ClassifiedArray(argv[2],vl,3);
    x.PopulateVector();

    cout<<"give me vector"<<endl;

}