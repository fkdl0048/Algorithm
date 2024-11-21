#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    for (char c : my_string) {
        if (isdigit(c)) {
            answer.push_back(c - '0');
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}