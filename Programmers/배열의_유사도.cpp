#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    unordered_set<string> set(s1.begin(), s1.end());
    
    for (string str : s2) {
        if (set.find(str) != set.end()) {
            answer++;
        }
    }
    
    return answer;
}