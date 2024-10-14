class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double max_sum = sum;

        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            max_sum = max(sum, max_sum);
        }

        return max_sum / k;
    }
};