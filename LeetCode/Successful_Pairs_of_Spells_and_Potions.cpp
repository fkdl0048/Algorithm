class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> result;

        for (int spell : spells) {
            long long minPotion = (success + spell - 1) / spell;
            int index = lowerBound(potions, minPotion);

            result.push_back(m - index);
        }

        return result;
    }

private:
    int lowerBound(const std::vector<int>& potions, long long target) {
        int left = 0;
        int right = potions.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (potions[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
