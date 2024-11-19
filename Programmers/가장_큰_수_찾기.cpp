#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> array) {
    priority_queue<pair<int, int>> pq;
    
    for (int i = 0; i < array.size(); i++) {
        pq.push({array[i], i});
    }
    
    return {pq.top().first, pq.top().second};
}