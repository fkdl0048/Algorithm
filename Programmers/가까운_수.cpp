#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    sort(array.begin(), array.end());
    
    int closest = array[0];
    int minDiff = abs(n - array[0]);
    
    for (int num : array) {
        int diff = abs(num - n);
        if (diff < minDiff) {
            minDiff = diff;
            closest = num;
        }
    }
    
    return closest;
}