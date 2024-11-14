#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    int pivot = 0;
    
    for (int i = 0; i < myString.length(); i++) {
        if (myString[i] == 'x') {
            string substring = myString.substr(pivot, i - pivot);
            if (!substring.empty()) { 
                answer.push_back(substring);
            }
            pivot = i + 1;
        }
    }
    
    if (pivot != myString.length()) {
        string last_substring = myString.substr(pivot);
        if (!last_substring.empty()) { 
            answer.push_back(last_substring);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}