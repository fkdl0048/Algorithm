#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxWidth = 0;
    int maxHeight = 0;
    
    for (const auto& size : sizes) {
        int w = size[0];
        int h = size[1];
        
        maxWidth = max(maxWidth, max(w, h));
        maxHeight = max(maxHeight, min(w, h));
    }
    
    return maxWidth * maxHeight;
}