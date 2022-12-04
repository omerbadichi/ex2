//
// Created by omer on 12/4/22.
//

#ifndef EX2_NAMEVECTOR_H
# include <vector>
# include <string>
using namespace std;
class NameVector {
private:
::vector<double> vector;
string name;
public:
    NameVector(string name,::vector<double> vector);
    ::vector<double> GetVector();
    string GetName();
    void SetVector (const ::vector<double>& vector1);
    void SetName(string name1);

};


#endif //EX2_NAMEVECTOR_H
