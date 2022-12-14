//
// Created by lidor on 12/6/22.
//
#include <vector>
using namespace std;
#include <string>
#include <iostream>
#include "Distance.h"
#include "ManhattanDistance.h"
#include "MinkowskiDistance.h"
#include "CanberraDistance.h"
#include "ChebyshevDistance.h"
#include "EuclideanDistance.h"
#include "Tools.h"
#include <fstream>

/**
 * this function represent any distance to enum.
 * @param dis
 * @return the distance wanted.
 */
distances whatDistance (const string& dis){
    if (dis == "AUC") {return AUC;}
    if (dis == "MAN") {return MAN;}
    if (dis == "CHB") {return CHB;}
    if (dis == "CAN") {return CAN;}
    if (dis == "MIN") {return MIN;}
    cout<<"invalid distance!";
    exit(0);
}
/**
 * the function receives a string and checks weather it can be modified into a double character.
 * @param s the string.
 * @return the answer weather the string is a valid double number.
 */
double IsValidDouble(const string& s){
   size_t index;
   double number=stod(s,&index);
   if(index<s.size()){
       string message="the vector is invalid";
       throw std::invalid_argument(message);
   }
    return number;
}

/**
 * check if the vector is same size.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return true or false.
 */
bool ValidVectors (const vector<double>& v1 ,const vector<double>& v2){
    return v1.size() == v2.size()&&!v1.empty();
}
/**
 * the function receives from the the user input, and devices it to doubles(if legal) and
 * spaces ,and each space indicates that we move to the next component.
 * @return the fully populated vector.
 */
vector<double> MakeVector () {
    //initialize the BufferEmpty to not be '\n'.
    char BufferEmpty='a';
    cout<<"enter a vector"<<endl;
    double number;
    string s;
    vector<double> v;
    while (BufferEmpty != '\n') {
        //this line informs to cin to not ignore whitespaces.
        cin.unsetf(ios_base::skipws);
        cin >> s;
        try{
            number= IsValidDouble(s);
        }catch(invalid_argument &e){
            cout<<"the vector is invalid"<<endl;
            exit(0);
        }
        v.push_back(number);
        cin >> BufferEmpty;
    }
    return v;
}
/**
 * this function return a reference.
 * @param dis enum that represent type of distance.
 * @return reference of class distance.
 */
Distance* GetDistanceFun(distances dis) {
    switch (dis) {
        case AUC:
            return new EuclideanDistance;
        case MAN:
            return new ManhattanDistance;
        case CHB:
            return new ChebyshevDistance;
        case CAN:
            return new CanberraDistance;
        case MIN:
            return new MinkowskiDistance;

    }
    return nullptr;
}
/**
 * check if k is number.
 * @param s , the string we wont to check.
 * @return
 */
bool IsValidK(const string& s){
    for(char i : s){
        if(!isdigit(i))
            return false;
    }
    return true;
}
