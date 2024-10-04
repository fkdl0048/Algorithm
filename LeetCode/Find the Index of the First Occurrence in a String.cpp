using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLen = haystack.length();
        int needleLen = needle.length();

        if (needleLen == 0) return 0;

        for (int i = 0; i <= haystackLen - needleLen; i++){
            if (haystack.substr(i, needleLen) == needle){
                return i;
            }
        }

        return -1;
    }
};