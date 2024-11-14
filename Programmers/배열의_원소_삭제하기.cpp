#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    unordered_set<int> to_delete(delete_list.begin(), delete_list.end());
    
    for (int num : arr) {
        if (to_delete.find(num) == to_delete.end()) {
            answer.push_back(num);
        }
    }
    
    return answer;
}