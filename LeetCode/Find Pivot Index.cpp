class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = 0;
        int left_sum = 0;

        for (int num : nums) {
            total_sum += num;
        }

        for (int i = 0; i < nums.size(); i++) {
            int right_sum = total_sum - left_sum - nums[i];

            if (right_sum == left_sum) {
                return i;
            }

            left_sum += nums[i];
        }

        return -1;
    }
};