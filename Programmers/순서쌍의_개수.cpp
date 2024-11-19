#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int result = 0;
    
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            result++;
        }
    }
    
    return result;
}