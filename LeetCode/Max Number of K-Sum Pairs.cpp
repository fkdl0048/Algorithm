class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;
        int operations = 0;

        for (int num : nums) {
            int complement = k - num;

            if (numCount[complement] > 0) {
                operations++;
                numCount[complement]--;
            } else {
                numCount[num]++;
            }
        }

        return operations;
    }
};

// 2회차 풀이

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int result = 0;
        int left = 0;
        int right = nums.size() - 1;

        sort(nums.begin(), nums.end());

        while (left < right) {
            if (nums[left] + nums[right] == k) {
                result++;
                left++;
                right--;
            }
            else if (nums[left] + nums[right] > k) {
                right--;
            }
            else if (nums[left] + nums[right] < k) {
                left++;
            }
        }

        return result;
    }
};