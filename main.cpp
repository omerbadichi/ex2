//
// Created by omer on 12/4/22.
//
# include <vector>
# include <cmath>
# include <string>
#include <iostream>
#include "ClassifiedArray.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main(int argc,char* argv[]){
    fstream fin;
    fin.open(argv[2],ios::in);
    string line,temp;
    while(fin>>temp){
        //getline(fin,line);
        cout<<temp<<endl;
    }

}