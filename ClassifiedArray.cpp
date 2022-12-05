//
// Created by omer on 12/4/22.
//

#include "ClassifiedArray.h"
#include <utility>
# include <vector>
# include <string>
#include <iostream>
#include <fstream>
#include <sstream>

ClassifiedArray::ClassifiedArray(string path , vector<double> ToCompare, int k, Distance *distance1) {
    this->path=std::move(path);
    this->ToCompare = std::move(ToCompare);
    this->k = k;
    this->distance = distance1;
}
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
vector<double>  ClassifiedArray:: MakeVector () {
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
void ClassifiedArray::PopulateVector() {
    fstream fin;
    fin.open(this->path,ios::in);
    string line,temp;
    while(fin>>temp){
        stringstream s(temp);
        vector<double> vec;
        while(getline(s,line,',')){
            if(IsValidDouble(line)){
                vec.push_back(stod(line));
            }else{
                NameVector v=NameVector(line,vec);
                if(vectors.empty())
                    vectors.push_back(v);
                else{
                    if(ValidVectors(vectors.at(0).GetVector(),vec))
                        vectors.push_back(v);
                    else{
                        cout<<"the vectors arent in the same size"<<endl;
                        exit(0);
                    }

                }
            }
        }

    }
}
bool CompareDistance(NameVector v1,NameVector v2){
    return v1.GetDistanceFromVector()<v2.GetDistanceFromVector();
}
void ClassifiedArray::SortByValue(){
    sort(vectors.begin(),vectors.end(), CompareDistance);
}
vector<NameVector> ClassifiedArray::GetVectors(){
    return vectors;
}
string ClassifiedArray::GetPath() {
    return path;
}
void ClassifiedArray::SetPath (string NewPath){
    path=std::move(NewPath);
}

void ClassifiedArray::PopulateDistance() {
    for (int i = 0; i < this->vectors.size(); ++i) {
        vectors.at(i).SetDistanceFromVector(distance->distance(ToCompare,vectors.at(i).GetVector()));
    }

}

