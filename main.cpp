//
// Created by omer on 12/4/22.
//
# include <string>
#include <iostream>
#include "ClassifiedArray.h"
using namespace std;
int main(int argc,char* argv[]){
ClassifiedArray x=ClassifiedArray(argv[2]);
x.PopulateVector();
int i=0;
while(x.GetVectors().size()>i) {
    cout<<x.GetVectors().at(i).GetName()<<endl;
    i++;
}
cout<<i;
}