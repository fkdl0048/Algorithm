class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n=strs.size();

        sort(strs.begin(), strs.end());
        string first = strs[0], last = strs[n-1];

        for (int i = 0; i < min(first.size(), last.size()); i++){
            if (first[i] != last[i])
                return ans;
            ans+=first[i];
        }
        
        return ans;
    }
};