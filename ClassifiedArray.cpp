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
#include "Tools.h"

ClassifiedArray::ClassifiedArray(string path , vector<double> ToCompare, int k, Distance *distance1) {
    this->path=std::move(path);
    this->ToCompare = std::move(ToCompare);
    this->k = k;
    this->distance = distance1;
}

void ClassifiedArray::PopulateVector() {
    fstream fin;
    fin.open(this->path,ios::in);
    if(!fin){
        cout<<"invalid path!"<<endl;
        exit(0);
    }
    string line,temp;
    while(fin>>temp){
        stringstream s(temp);
        vector<double> vec;
        while(getline(s,line,',')){
            if(IsValidDouble(line)){
                vec.push_back(stod(line));
            }else{
                NameVector v=NameVector(line,vec);
                if(vectors.empty()) {
                        vectors.push_back(v);
                }
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
    fin.close();
}
string ClassifiedArray::FindClassification(){
    map<string,int> map;
    for(int i=0;i<this->k;i++){
        if(map.count(this->vectors.at(i).GetName())){
            map.at(this->vectors.at(i).GetName())++;
        }else{
            map.insert({this->vectors.at(i).GetName(),1});
        }
}
    string curr;
    int max=0;
    for(auto & it : map){
        if(max<it.second) {
            curr = it.first;
            max=it.second;
        }
    }
    return curr;
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
    if(ValidVectors(this->ToCompare,this->vectors.at(0).GetVector())) {
        for (int i = 0; i < this->vectors.size(); ++i) {
            vectors.at(i).SetDistanceFromVector(distance->distance(ToCompare, vectors.at(i).GetVector()));
        }
    }
    else{
        cout<<"invalid vector!"<<endl;
        exit(0);
    }

}


int ClassifiedArray::GetK() {
    return this->k;
}

void ClassifiedArray::SetK(int k) {
    this->k = k;
}
string ClassifiedArray::KNN() {
    PopulateDistance();
    SortByValue();
    return FindClassification();

}

void ClassifiedArray::SetVectorToCompare(const vector<double>& vector) {
    this->ToCompare=std::move(ToCompare);

}

   

