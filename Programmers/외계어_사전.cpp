#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    string target = "";
    
    for (const string& s : spell) {
        target += s;
    }
    
    sort(target.begin(), target.end());
    
    for (string word : dic) {
        if (word.length() != target.length()) {
            continue;
        }
        
        sort(word.begin(), word.end());
        
        if (word == target) {
            return 1;
        }
    }
    
    return 2;
}