#include <string>
#include <vector>

using namespace std;

int combination(int n, int m) {
    if (n == m) return 1;
    if (m == 1) return n;
    
    return combination(n - 1, m - 1) + combination(n - 1, m);
}

int solution(int balls, int share) {
    return combination(balls, share);
}