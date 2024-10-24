#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, h, mid)) {
                result = mid;
                right = mid - 1; // 더 작은 속도로 시도
            } else {
                left = mid + 1; // 더 큰 속도로 시도
            }
        }

        return result;
    }

private:
    bool canFinish(const std::vector<int>& piles, int h, int k) {
        long long totalHours = 0;
        for (int pile : piles) {
            totalHours += (pile + k - 1) / k; // 올림 계산
            if (totalHours > h) {
                return false; // 이미 시간이 초과함
            }
        }
        return totalHours <= h;
    }
};
