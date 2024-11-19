#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string numstr = to_string(n);
    
    for (char n : numstr) {
        answer += n - '0';
    }
    
    return answer;
}