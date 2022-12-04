//
// Created by omer on 12/4/22.
//

#include "ClassifiedArray.h"
/**
 * the function receives a string and checks weather it can be modified into a double character.
 * @param s the string.
 * @return the answer weather the string is a valid double number.
 */
bool ClassifiedArray::IsValidDouble(const string& s){
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
 * the function receives from the the user input, and devices it to doubles(if legal) and
 * spaces ,and each space indicates that we move to the next component.
 * @return the fully populated vector.
 */
vector<double>  ClassifiedArray:: GetVector () {
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
/**
 * check if the vector is same size.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return true or false.
 */
bool ClassifiedArray::ValidVectors (const vector<double>& v1 ,const vector<double>& v2){
    return v1.size() == v2.size()&&!v1.empty();
}