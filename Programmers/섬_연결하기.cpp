#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if(rootX == rootY) return;
        
        if(rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            if(rank[rootX] == rank[rootY]) {
                rank[rootX]++;
            }
        }
    }
};

int solution(int n, vector<vector<int>> costs) {
    // 비용 기준으로 정렬
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    
    DisjointSet ds(n);
    int totalCost = 0;
    
    for(const auto& cost : costs) {
        int from = cost[0];
        int to = cost[1];
        int weight = cost[2];
        
        if(ds.find(from) != ds.find(to)) {
            ds.unionSet(from, to);
            totalCost += weight;
        }
    }
    
    return totalCost;
}