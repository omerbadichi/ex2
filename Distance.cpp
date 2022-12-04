//
// Created by omer on 12/4/22.
//

#include "Distance.h"
using namespace std;

/**
 * This function calculate the distance between two vector by canberra.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the distance.
 */
double Distance:: canberra (vector<double> v1 , vector<double> v2){
    double distance, sum = 0, AbsV1, AbsV2;
    for (int i = 0; i < v1.size(); ++i) {
        distance = abs(v1.at(i)-v2.at(i));
        AbsV1 = abs(v1.at(i));
        AbsV2 = abs(v2.at(i));
        if (AbsV1 == 0 && AbsV2 == 0)
            continue;
        sum += distance/(AbsV1 + AbsV2);
    }
    return sum;
}
/**
 * This function calculate the distance between two vector by minkowski.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @param p the default p that with it we calculate the distance.
 * @return the distance.
 */
double Distance::minkowski (vector<double> v1 , vector<double> v2,double p){
    double sum=0, distance, result;
    for (int i = 0; i < v1.size(); ++i) {
        distance = abs(v1.at(i)-v2.at(i));
        sum += pow(distance,p);
    }
    result = pow(sum,(1/p));
    return result;

}
/**
 * calculates the euclidean distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the euclidean distance between the two vectors.
 */
double Distance::euclidean(vector<double> v1,vector<double> v2){
    double sum=0;
    for(int i=0;i<v1.size();i++){
        sum+= pow(v1.at(i)-v2.at(i),2);
    }
    return sqrt(sum);
}
/**
 * calculates the manhattan distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the manhattan distance between the two vectors.
 */
double Distance::manhattan(vector<double> v1,vector<double> v2){
    double sum=0;
    for(int i=0;i<v1.size();i++){
        sum+= abs(v1.at(i)-v2.at(i));
    }
    return sum;
}
/**
 * calculates the chebyshev distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the chebyshev distance between the two vectors.
 */
double Distance::chebyshev(vector<double> v1,vector<double> v2){
    double max=0;
    for(int i=0;i<v1.size();i++){
        double cur=abs(v1.at(i)-v2.at(i));
        if(max<cur)
            max=cur;
    }
    return max;
}
