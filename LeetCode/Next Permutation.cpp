class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: 오른쪽에서부터 첫 감소하는 위치를 찾기
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Step 2: 그 값보다 큰 값 중 가장 작은 값과 교체
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        // Step 3: i 이후의 배열을 오름차순으로 변경
        reverse(nums.begin() + i + 1, nums.end());
    }
};