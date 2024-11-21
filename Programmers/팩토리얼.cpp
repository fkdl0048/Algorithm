#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int i = 1;
    int factorial = 1;
    
    while (factorial <= n) {
        factorial *= i;
        i++;
    }
    
    return i - 2;
}