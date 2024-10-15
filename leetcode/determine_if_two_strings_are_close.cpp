class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        vector<int> freq1(26, 0), freq2(26, 0);
        vector<int> exists1(26, 0), exists2(26, 0);

        for (char c : word1) {
            freq1[c - 'a']++;
            exists1[c - 'a'] = 1;
        }

        for (char c : word2) {
            freq2[c - 'a']++;
            exists2[c - 'a'] = 1;
        }

        if (exists1 != exists2) {
            return false;
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};
