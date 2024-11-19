#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(string my_string) {
    unordered_map<char, int> m;
    string answer = "";
    
    m['a']++;
    m['e']++;
    m['i']++;
    m['o']++;
    m['u']++;
    
    for (char c : my_string) {
        if (!m[c]) {
            answer += c;
        }
    }
    
    return answer;
}