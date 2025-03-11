// 주어진 문자열에서 a, b, c 모두 등장하는
// 부분 문자열의 개수를 찾아서 반환하기
//

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = (int)s.size();

        int lastA = -1, lastB = -1, lastC = -1;

        long long result = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') lastA = i;
            else if (s[i] == 'b') lastB = i;
            else if (s[i] == 'c') lastC = i;

            int minPos = min({lastA, lastB, lastC});

            if (minPos != -1) {
                result += (minPos + 1);
            }
        }

        return result;      
    }
};