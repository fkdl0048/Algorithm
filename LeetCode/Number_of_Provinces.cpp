// dfs로 풀이,
// n개까지 반복하는데, 방분하지 않은 곳일 경우 dfs를 타서 방문 노드를 찍음
// 이 반복에서 provinces를 증감하면 됨

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                dfs(isConnected, visited, i);
                provinces++;
            }
        }

        return provinces;
    }
private:
    void dfs(const vector<vector<int>>& isConnected, vector<bool>& visited, int city) {
        visited[city] = true;

        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[city][i] == 1 && visited[i] == false) {
                dfs(isConnected, visited, i);
            }
        }
    }
};
