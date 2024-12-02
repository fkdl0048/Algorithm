#include <string>
#include <vector>
#include <queue>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    map<int, int> numCount;
    
    for (const string& op : operations) {
        stringstream ss(op);
        char command;
        int number;
        ss >> command >> number;
        
        if (command == 'I') {
            maxHeap.push(number);
            minHeap.push(number);
            numCount[number]++;
        } 
        else if (!maxHeap.empty()) {
            int target;
            if (number == 1) {
                while (!maxHeap.empty() && numCount[maxHeap.top()] == 0) {
                    maxHeap.pop();
                }
                if (!maxHeap.empty()) {
                    target = maxHeap.top();
                    maxHeap.pop();
                    numCount[target]--;
                }
            } 
            else {
                while (!minHeap.empty() && numCount[minHeap.top()] == 0) {
                    minHeap.pop();
                }
                if (!minHeap.empty()) {
                    target = minHeap.top();
                    minHeap.pop();
                    numCount[target]--;
                }
            }
        }
        
        while (!maxHeap.empty() && numCount[maxHeap.top()] == 0) {
            maxHeap.pop();
        }
        while (!minHeap.empty() && numCount[minHeap.top()] == 0) {
            minHeap.pop();
        }
    }
    
    if (maxHeap.empty() || minHeap.empty()) {
        return {0, 0};
    }
    return {maxHeap.top(), minHeap.top()};
}