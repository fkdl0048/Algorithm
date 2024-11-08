#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int len = num_list.size();
    
    if (len <= 10) {
        answer = 1;
        for (int n : num_list) {
            answer *= n;
        }
    } else {
        for (int n : num_list) {
            answer += n;
        }
    }
    
    return answer;
}