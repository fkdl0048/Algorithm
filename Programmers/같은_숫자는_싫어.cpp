#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    stack<int> s;
    vector<int> result;
    
    s.push(arr[0]);
    for (int num : arr) {
        if (s.top() != num) {
            s.push(num);
        }
    }
    
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    
    reverse(result.begin(), result.end());

    return result;
}