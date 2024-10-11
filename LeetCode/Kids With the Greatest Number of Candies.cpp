class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> result(n, false);

        int max = 0;
        for (int i = 0; i < n; i++) {
            if (max < candies[i]) {
                max = candies[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (max <= candies[i] + extraCandies) {
                result[i] = true;
            }
        }

        return result;
    }
};