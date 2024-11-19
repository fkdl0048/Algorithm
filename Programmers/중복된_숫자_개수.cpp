#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> array, int n) {
    unordered_map<int, int> m;
    for (int num : array) {
        m[num]++;
    }
    
    return m[n];
}