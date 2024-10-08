class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // 배열을 정렬하는 대신, 각 숫자를 그 숫자가 있어야 할 위치로 이동
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // 첫 번째로 잘못된 위치의 숫자 찾기
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // 모든 숫자가 제자리에 있을 경우, n + 1이 첫 번째 누락된 양수
        return n + 1;
    }
};