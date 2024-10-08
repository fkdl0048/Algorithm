class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;

        sort(candidates.begin(), candidates.end());
        backTrack(candidates, target, 0, currentCombination, result);
        return result;
    }

private:
    void backTrack(vector<int>& candidates, int target, int index, vector<int>& currentCombination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }

        if (target < 0) return;

        for (int i = index; i < candidates.size(); i++) {

            if (i > index && candidates[i] == candidates[i - 1]) continue;

            currentCombination.push_back(candidates[i]);
            backTrack(candidates, target - candidates[i], i + 1, currentCombination, result);
            currentCombination.pop_back();
        }
    }
};