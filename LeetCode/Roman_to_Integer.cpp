class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        unordered_map<char, int> m {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        for (int i = 0; i < s.length(); i++){
            if (m[s[i]] < m[s[i + 1]])
                result -= m[s[i]];
            else
                result += m[s[i]];
        }

        return result;
    }
};