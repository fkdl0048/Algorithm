#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(string my_string) {
    unordered_set<char> set;
    string answer = "";
    
    for (char c : my_string) {
        if (set.find(c) == set.end()) {
            set.insert(c);
            answer += c;
        }
    }
    
    return answer;
}