#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer(emergency.size(), 0);
    vector<pair<int, int>> pairs;
    
    for (int i = 0; i < emergency.size(); i++) {
        pairs.push_back({emergency[i], i});
    }
    
    sort(pairs.rbegin(), pairs.rend());
    
    for (int i = 0; i < pairs.size(); i++) {
        answer[pairs[i].second] = i + 1;
    }
    
    return answer;
}