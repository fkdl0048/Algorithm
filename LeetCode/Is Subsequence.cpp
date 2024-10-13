class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sp = 0, tp = 0;

        while (s.size() > sp && t.size() > tp) {
            if (s[sp] == t[tp]) {
                sp++;
            }
            tp++;
        }

        return sp == s.size();
    }
};