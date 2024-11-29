// progresse와 speed를 넘기면 작업 시간을 반환해주는 함수
// 반복으로 작업시간을 가지고 

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> result;
    queue<int> daysQueue;
    
    for (size_t i = 0; i < progresses.size(); ++i) {
        int remainingProgress = 100 - progresses[i];
        int days = (remainingProgress + speeds[i] - 1) / speeds[i];
        daysQueue.push(days);
    }
    
    while (!daysQueue.empty()) {
        int currentDay = daysQueue.front();
        daysQueue.pop();
        int count = 1;
        
        while (!daysQueue.empty() && daysQueue.front() <= currentDay) {
            daysQueue.pop();
            count++;
        }
        
        result.push_back(count);
    }
    
    return result;
}