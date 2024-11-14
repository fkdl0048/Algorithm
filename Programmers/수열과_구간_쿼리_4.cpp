#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for (const auto& query : queries) {
        int s = query[0];
        int e = query[1];
        int k = query[2];
        
        if (k == 0) continue;
        
        for (int i = s; i <= e; i++) {
            if (i % k == 0) {
                arr[i]++;
            }
        }
    }
    
    return arr;
}