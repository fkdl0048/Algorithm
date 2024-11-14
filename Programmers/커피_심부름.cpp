#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    
    for (const auto& str : order) {
        if (str.find("americano") != string::npos || str.find("anything") != string::npos) {
            answer += 4500;
        } else {
            answer += 5000;
        }
    }
    
    return answer;
}