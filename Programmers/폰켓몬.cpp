#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    
    return nums.size() / 2 < s.size() ? nums.size() / 2 : s.size();
}