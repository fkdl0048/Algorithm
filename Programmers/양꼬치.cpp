#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    int service = n / 10;
    k -= service;
    
    answer += n * 12000;
    if (k > 0) {
        answer += k * 2000;
    }
    
    return answer;
}