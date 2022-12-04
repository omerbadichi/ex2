//
// Created by omer on 12/4/22.
//
#include "NameVector.h"

#include <utility>
vector<double> NameVector::GetVector() {return vector;}
string NameVector::GetName() {return name;}
void NameVector::SetName(string name1) {name = std::move(name1);}
void NameVector::SetVector(const ::vector<double>& vector1) { vector = vector1;}
