#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        backtrack(1, k, n, combination, result);
        return result;
    }

private:
    void backtrack(int start, int k, int n, std::vector<int>& combination,
                   std::vector<std::vector<int>>& result) {
        if (combination.size() == k && n == 0) {
            result.push_back(combination);
            return;
        }
        if (combination.size() > k || n < 0) {
            return;
        }
        for (int i = start; i <= 9; ++i) {
            combination.push_back(i);
            backtrack(i + 1, k, n - i, combination, result);
            combination.pop_back(); // 백트래킹
        }
    }
};
