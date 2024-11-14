#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strArr) {
    for (int i = strArr.size() - 1; i >= 0; i--) {
        if (strArr[i].find("ad") != string::npos) {
            strArr.erase(strArr.begin() + i);
        }
    }
    
    return strArr;
}