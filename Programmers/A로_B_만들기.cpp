#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string before, string after) {
    unordered_map<char, int> m1;
    unordered_map<char, int> m2;
    
    for (char c : before) {
        m1[c]++;
    }
    for (char c : after) {
        m2[c]++;
    }

    return m1 == m2 ? 1 : 0;
}