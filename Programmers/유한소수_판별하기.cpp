#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int solution(int a, int b) {
    int g = gcd(a, b);
    b /= g;
    
    if(b == 1) return 1;
    
    while(b % 2 == 0) {
        b /= 2;
    }
    
    while(b % 5 == 0) {
        b /= 5;
    }
    
    return (b == 1) ? 1 : 2;
}