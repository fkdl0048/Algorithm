#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    for (int n : array) {
        for (char c : to_string(n)) {
            if (c == '7') {
                answer++;
            }
        }
    }
    
    return answer;
}