// 마찬가지로 스택 문제
// 양수를 넣고 음수가 나오면 top을 비교하여 크다면 pop아니라면 넘어감
// 이후 stack을 vector로 변환 후 반환

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> result;

        for (int asteroid : asteroids) {
            if (asteroid > 0) {
                s.push(asteroid);
            }
            else {
                while (!s.empty() && s.top() > 0 && s.top() < abs(asteroid)) {
                    s.pop();
                }

                if (s.empty() || s.top() < 0) {
                    s.push(asteroid);
                }

                if (!s.empty() && s.top() == abs(asteroid)) {
                    s.pop();
                }
            }
        }

        while(!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
