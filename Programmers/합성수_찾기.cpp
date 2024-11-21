#include <string>
#include <vector>

using namespace std;

int countDivisors(int n) {
    int count = 0;
    
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    
    return count;
}

int solution(int n) {
    int answer = 0;
    
    for (int i = 1; i <= n; i++) {
        if (countDivisors(i) >= 3) {
            answer++;
        }
    }
    
    return answer;
}