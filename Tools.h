//
// Created by lidor on 12/6/22.
//

#ifndef EX2_TOOLS_H
#define EX2_TOOLS_H
enum distances {
    AUC,
    MAN,
    CHB,
    CAN,
    MIN
};
distances whatDistance (const string& dis);
bool IsValidDouble(const string& s);
bool ValidVectors (const vector<double>& v1 ,const vector<double>& v2);
vector<double> MakeVector ();
Distance* GetDistanceFun(const string& dis);



#endif //EX2_TOOLS_H
