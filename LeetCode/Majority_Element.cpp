#include <unordered_map>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;

        for (int num : nums) {
            m[num]++;
        }

        int maxCount = 0;
        int maxNum = 0;
        for (auto pair : m) {
            if (pair.second > maxCount) {
                maxNum = pair.first;
                maxCount = pair.second;
            }
        }
        
        return maxNum;
    }
};