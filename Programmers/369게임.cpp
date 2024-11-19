#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int result = 0;
    
    for (char c : to_string(order)) {
        if (c == '3' || c == '6' || c == '9') {
            result++;
        }
    }
    
    return result;
}