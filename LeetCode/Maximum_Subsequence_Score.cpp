#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        int n = nums1.size();
        // nums2의 값과 해당 인덱스를 페어로 묶어 저장
        std::vector<std::pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = { nums2[i], nums1[i] };
        }

        // nums2를 기준으로 내림차순 정렬
        std::sort(pairs.rbegin(), pairs.rend());

        // 최소 힙 사용
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        long long sum = 0;
        long long result = 0;

        for (auto& [num2, num1] : pairs) {
            minHeap.push(num1);
            sum += num1;

            // 힙의 크기가 k를 초과하면 가장 작은 nums1 값을 제거
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            // 힙의 크기가 k일 때 점수 계산
            if (minHeap.size() == k) {
                result = std::max(result, sum * num2);
            }
        }

        return result;
    }
};
