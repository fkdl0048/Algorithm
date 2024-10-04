class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs(result, "", 0, 0, n);
        return result;
    }
private:
    void dfs(vector<string>& res, string current, int open, int close, int n){
        if (current.length() == n * 2){
            res.push_back(current);
            return;
        }

        if (open < n){
            dfs(res, current + "(", open + 1, close, n);
        }
        
        if (close < open){
            dfs(res, current + ")", open, close + 1, n);
        }
    }
};