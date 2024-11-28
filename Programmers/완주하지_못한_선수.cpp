#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    
    for (string str : participant) {
        m[str]++;
    }
    
    for (string str : completion) {
        m[str]--;
    }
    
    
    for (auto pair : m) {
        if (pair.second >= 1) {
            return pair.first;
        }
    }
    
    return "";
}