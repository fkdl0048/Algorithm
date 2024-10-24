#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
    
        while (left < right) {
            int mid = left + (right - left) / 2;
    
            if (nums[mid] > nums[mid + 1]) {
                // 왼쪽에 피크가 있음
                right = mid;
            } else {
                // 오른쪽에 피크가 있음
                left = mid + 1;
            }
        }
    
        return left;
    }
};
