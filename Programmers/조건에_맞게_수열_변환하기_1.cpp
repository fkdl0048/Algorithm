#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for (int n : arr) {
        if (n >= 50 && n % 2 == 0) {
            answer.push_back(n / 2);
        }
        else if (n < 50 && n % 2 == 1) {
            answer.push_back(n * 2);
        } else {
            answer.push_back(n);
        }
    }
    
    return answer;
}