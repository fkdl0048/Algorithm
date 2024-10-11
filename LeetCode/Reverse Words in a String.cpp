using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string str;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                str += s[i];
            } else {
                if (!str.empty()) {
                    words.push_back(str);
                    str.clear();
                }
            }
        }

        if (!str.empty()) {
            words.push_back(str);
        }

        str.clear();
        reverse(words.begin(), words.end());

        for (int i = 0; i < words.size(); i++) {
            str += words[i];
            if (i != words.size() - 1) {
                str += ' ';
            }
        }

        return str;
    }
};