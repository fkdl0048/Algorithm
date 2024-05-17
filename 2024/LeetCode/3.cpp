#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxLength = 0;
    unordered_set<char> charSet;
    int left = 0;
    
    for (int right = 0; right < n; right++) {
        if (charSet.count(s[right]) == 0) {
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        } else {
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
        }
    }
    
    return maxLength;
}

int main() {
    string s;
    cout << "문자열을 입력하세요: ";
    cin >> s;

    int result = lengthOfLongestSubstring(s);
    cout << "반복되는 문자가 없는 가장 긴 부분 문자열의 길이: " << result << endl;

    return 0;
}