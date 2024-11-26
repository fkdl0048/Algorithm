#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    
    sort(numlist.begin(), numlist.end(), [n](int a, int b) {
        int distA = abs(a - n);
        int distB = abs(b - n);
        
        if (distA == distB) {
            return a > b;
        }
        
        return distA < distB;
    });
    
    return numlist;
}