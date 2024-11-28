#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> m;
    
    for (const auto& item : clothes) {
        m[item[1]]++;
    }
    
    int combinations = 1;
    for (const auto& pair : m) {
        combinations *= (pair.second + 1);
    }

    return combinations - 1;
}