#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> queueR, queueD;
        int n = senate.size();

        // Radiant와 Dire 상원의원의 인덱스를 각각의 큐에 저장
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                queueR.push(i);
            } else {
                queueD.push(i);
            }
        }

        // 두 큐가 비어있지 않으면 계속 투표
        while (!queueR.empty() && !queueD.empty()) {
            int r_index = queueR.front();
            int d_index = queueD.front();
            queueR.pop();
            queueD.pop();

            // 더 작은 인덱스의 상원의원이 상대방을 추방하고, 다음 투표를 준비
            if (r_index < d_index) {
                // Radiant 상원의원이 이겼으므로, 다시 투표 가능
                queueR.push(r_index + n);
            } else {
                // Dire 상원의원이 이겼으므로, 다시 투표 가능
                queueD.push(d_index + n);
            }
        }

        // Radiant 상원의원이 남아 있으면 Radiant 승리, 아니면 Dire 승리
        return queueR.empty() ? "Dire" : "Radiant";
    }
};
