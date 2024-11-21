#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    map<char, int> map;
    string answer = "";
    
    for (char c : s) {
        map[c]++;
    }
    
    for (const auto& it : map) {
        if (it.second == 1) {
            answer += it.first;
        }
    }
    
    return answer;
}