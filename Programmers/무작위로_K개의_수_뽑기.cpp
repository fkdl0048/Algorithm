#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    unordered_set<int> used;
    
    for(int num : arr) {
        if(used.find(num) == used.end()) {
            answer.push_back(num);
            used.insert(num);
            if(answer.size() == k) break;
        }
    }
    
    while(answer.size() < k) {
        answer.push_back(-1);
    }
    
    return answer;
}