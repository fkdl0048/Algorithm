#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    
    for (int i = 0; i < queries.size(); i++) {
        for (int j = queries[i][0]; j <= queries[i][1]; j++) {
            arr[j]++;
        }
    }
    
    return arr;
}