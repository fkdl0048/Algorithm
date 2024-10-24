#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

class Solution {
public:
    long long totalCost(std::vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long totalCost = 0;
        int left = 0;
        int right = n - 1;

        // 최소 힙 정의: 비용, 인덱스
        using Worker = std::pair<int, int>;
        auto cmp = [](const Worker& a, const Worker& b) {
            if (a.first == b.first)
                return a.second > b.second; // 비용이 같으면 인덱스가 작은 순
            return a.first > b.first; // 비용이 작은 순
        };
        std::priority_queue<Worker, std::vector<Worker>, decltype(cmp)> leftHeap(cmp);
        std::priority_queue<Worker, std::vector<Worker>, decltype(cmp)> rightHeap(cmp);

        // 초기 힙 구성
        for (; left < candidates && left <= right; ++left) {
            leftHeap.emplace(costs[left], left);
        }
        for (; right >= n - candidates && right >= left; --right) {
            rightHeap.emplace(costs[right], right);
        }

        // k번의 고용 세션 진행
        for (int i = 0; i < k; ++i) {
            if (leftHeap.empty()) {
                auto [cost, idx] = rightHeap.top();
                rightHeap.pop();
                totalCost += cost;

                if (right >= left) {
                    rightHeap.emplace(costs[right], right);
                    --right;
                }
            }
            else if (rightHeap.empty()) {
                auto [cost, idx] = leftHeap.top();
                leftHeap.pop();
                totalCost += cost;

                if (left <= right) {
                    leftHeap.emplace(costs[left], left);
                    ++left;
                }
            }
            else {
                // 두 힙에서 최솟값 비교
                auto [leftCost, leftIdx] = leftHeap.top();
                auto [rightCost, rightIdx] = rightHeap.top();

                if (leftCost < rightCost || (leftCost == rightCost && leftIdx < rightIdx)) {
                    leftHeap.pop();
                    totalCost += leftCost;

                    if (left <= right) {
                        leftHeap.emplace(costs[left], left);
                        ++left;
                    }
                }
                else {
                    rightHeap.pop();
                    totalCost += rightCost;

                    if (right >= left) {
                        rightHeap.emplace(costs[right], right);
                        --right;
                    }
                }
            }
        }

        return totalCost;
    }
};
