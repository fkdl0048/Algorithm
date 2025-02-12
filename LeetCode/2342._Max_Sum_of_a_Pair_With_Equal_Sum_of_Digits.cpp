// 자리수 합을 키로 가지는 map을 만들고
// 가장 위에 있는 수를 key로 출력

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, list<int>> m;

        for (int n : nums) {

            int digitSum = 0;
            int temp = n;
            while (temp != 0) {
                digitSum += temp % 10;
                temp = temp / 10;
            }

            m[digitSum].push_back(n);
        }

        int result = -1;

        for (auto &entry : m) {
            list<int>& valuse = entry.second;

            if (valuse.size() >= 2) {
                
                valuse.sort(greater<int>());

                auto it = valuse.begin();
                int first = *it;
                ++it;
                int second = *it;

                result = max(result, first + second);
            }
        }

        return result;
    }
};