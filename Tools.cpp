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

distances whatDistance (const string& dis){
    if (dis == "AUC") {return AUC;}
    if (dis == "MAN") {return MAN;}
    if (dis == "CHB") {return CHB;}
    if (dis == "CAN") {return CAN;}
    if (dis == "MIN") {return MIN;}
}
/**
 * the function receives a string and checks weather it can be modified into a double character.
 * @param s the string.
 * @return the answer weather the string is a valid double number.
 */
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

Distance* GetDistanceFun(const string& dis) {
    switch (whatDistance(dis)) {
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
        default:
            cout<<"error!";
            exit(0);
    }

}
