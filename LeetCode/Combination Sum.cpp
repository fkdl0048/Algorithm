class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombiation;
        backTrack(candidates, 0, target, currentCombiation, result);
        return result;
    }

private:
    void backTrack(vector<int>& candidates, int startIdx, int target, vector<int>& currentCombiation, vector<vector<int>>& result){
        if (target == 0) {
            result.push_back(currentCombiation);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = startIdx; i < candidates.size(); i++) {
            currentCombiation.push_back(candidates[i]);
            backTrack(candidates, i, target - candidates[i], currentCombiation, result);
            currentCombiation.pop_back();
        }
    }
};