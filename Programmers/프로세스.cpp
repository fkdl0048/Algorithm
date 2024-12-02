#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    int count = 0;
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        
        if (pq.top() == temp.second) {
            count++;
            pq.pop();
            if (temp.first == location) {
                return count;
            }
        } else {
            q.push(temp);
        }
    }
    
    return count;
}