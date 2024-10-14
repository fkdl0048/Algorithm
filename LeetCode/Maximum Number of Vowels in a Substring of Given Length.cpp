class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = s.size();
        int current_vowel_count = 0;
        int max_vowel_count = 0;

        for (int i = 0; i < k; i++) {
            if (vowels.count(s[i])) {
                current_vowel_count++;
            }
        }
        max_vowel_count = current_vowel_count;

        for (int i = k; i < n; i++) {

            if (vowels.count(s[i])) {
                current_vowel_count++;
            }

            if (vowels.count(s[i - k])) {
                current_vowel_count--;
            } 

            max_vowel_count = max(current_vowel_count, max_vowel_count);
        }

        return max_vowel_count;
    }
};