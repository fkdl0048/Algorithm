#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> strArr) {
    unordered_map<int, int> lengthCount;
    
    for (const string& str : strArr) {
        lengthCount[str.length()]++;
    }
    
    int maxCount = 0;
    for (const auto& pair : lengthCount) {
        maxCount = max(maxCount, pair.second);
    }
    
    return maxCount;
}