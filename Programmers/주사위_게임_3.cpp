#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int a, int b, int c, int d) {
    // 숫자의 빈도수 계산
    map<int, int> freq;
    freq[a]++; freq[b]++; freq[c]++; freq[d]++;
    
    // 빈도수 기준으로 case 분류
    if(freq.size() == 1) {
        // 모든 주사위가 같은 경우
        return 1111 * a;
    }
    
    if(freq.size() == 2) {
        // 3+1 또는 2+2
        for(auto pair : freq) {
            if(pair.second == 3) {
                // 3개가 같은 경우
                int p = pair.first;
                int q = 0;
                for(auto other : freq) {
                    if(other.second == 1) q = other.first;
                }
                return (10 * p + q) * (10 * p + q);
            }
        }
        // 2+2인 경우
        int p = 0, q = 0;
        for(auto pair : freq) {
            if(p == 0) p = pair.first;
            else q = pair.first;
        }
        return (p + q) * abs(p - q);
    }
    
    if(freq.size() == 3) {
        // 2개가 같고 나머지가 다른 경우
        int p = 0, q = 0, r = 0;
        for(auto pair : freq) {
            if(pair.second == 2) p = pair.first;
            else if(q == 0) q = pair.first;
            else r = pair.first;
        }
        return q * r;
    }
    
    // 모두 다른 경우
    return min({a, b, c, d});
}