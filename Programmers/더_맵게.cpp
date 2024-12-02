#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int s : scoville) {
        pq.push(s);
    }
    
    int mixCount = 0;
    
    while (pq.size() >= 2 && pq.top() < K) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        int newScoville = first + (second * 2);
        pq.push(newScoville);
        mixCount++;
    }
    
    return (pq.top() >= K) ? mixCount : -1;
}