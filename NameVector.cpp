//
// Created by omer on 12/4/22.
//
#include "NameVector.h"

#include <utility>
string NameVector::GetName() {return name;}
void NameVector::SetName(string name1) {name = std::move(name1);}
void NameVector::SetVector(const ::vector<double>& vector1) { vector = vector1;}
vector<double> NameVector::GetVector() { return this->vector;}
NameVector::NameVector(string name, ::vector<double> vector) {
    this->name=std::move(name);
    this->vector=std::move(vector);
}

void NameVector::SetDistanceFromVector(double distance) {
    this->DistanceFromVector=distance;
}

double NameVector::GetDistanceFromVector() {
    return this->DistanceFromVector;

}
