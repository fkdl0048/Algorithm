#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    int n = score.size();
    vector<double> avg(n);
    vector<int> ranks(n, 1);
    
    for (int i = 0; i < n; i++) {
        avg[i] = (score[i][0] + score[i][1]) / 2.0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (avg[i] < avg[j]) {
                ranks[i]++;
            }
        }
    }
    
    return ranks;
}