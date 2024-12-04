#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n);
        k = k % n;

        for (int i = 0; i < n; i++) {
            result[(k + i) % n] = nums[i];
        }

        nums = result;
    }
};