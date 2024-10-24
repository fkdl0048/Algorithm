class Solution {
public:
    int count = 0;
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj) {
        for (auto& [neighbor, sign] : adj[node]) {
            if (neighbor != parent) {
                count += sign;
                dfs(neighbor, node, adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        dfs(0, -1, adj);

        return count;
    }
};
