#include <string>
#include <vector>

using namespace std;

bool isValid(int num) {
    if(num % 3 == 0) return false;
    
    while(num > 0) {
        if(num % 10 == 3) return false;
        num /= 10;
    }
    
    return true;
}

int solution(int n) {
    int result = 0;
    int count = 0;
    
    for(int i = 1; count < n; i++) {
        if(isValid(i)) {
            count++;
            result = i;
        }
    }
    
    return result;
}