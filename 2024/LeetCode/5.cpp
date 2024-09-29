class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }

        vector<string> v(numRows, "");

        int j = 0, dir = -1;

        for (int i = 0; i < s.length(); i++)
        {
            if (j == numRows - 1 || j == 0)
            {
                dir *= -1;
            }
            
            v[j] += s[i];
            if (dir == 1) j++;
            else j--;
        }

        string res;
        for (auto &it : v)
        {
            res += it;
        }

        return res;
    }
};

// if numsRows = 3
// 0,    4,    8,     12
// 1, 3, 5, 7, 9, 11, 13
// 2,    6,    10

// if numsRows = 4
// 0,      6,       12,
// 1,   5, 7,    11,13,
// 2, 4,   8, 10,   14,
// 3,      9,       15,

// 배열을 N개만큼 만들고 현재 인수에서 N개까지 증가, N개만큼 감소 반복.
// 배열 순서대로 붙이기