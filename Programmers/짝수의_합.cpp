#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int result = 0;
    
    while (n > 0) {
        if (n % 2 == 0) {
            result += n;
        }
        
        n--;
    }
    
    return result;
}