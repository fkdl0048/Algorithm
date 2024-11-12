#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    
    for (int i = 1; i < numLog.size(); i++) {
        if (numLog[i - 1] + 1 == numLog[i]) {
            answer += 'w';
        } else if (numLog[i - 1] - 1 == numLog[i]) {
            answer += 's';
        } else if (numLog[i - 1] + 10 == numLog[i]) {
            answer += 'd';
        } else if (numLog[i - 1] - 10 == numLog[i]) {
            answer += 'a';
        } 
    }
    
    return answer;
}