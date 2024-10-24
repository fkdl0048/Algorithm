#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class Solution {
public:
    double dfs(const std::string& curr, const std::string& target,
               std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& graph,
               std::unordered_map<std::string, bool>& visited) {
        if (graph.find(curr) == graph.end() || graph.find(target) == graph.end())
            return -1.0;
        if (curr == target)
            return 1.0;

        visited[curr] = true;
        for (const auto& neighbor : graph[curr]) {
            const std::string& next = neighbor.first;
            double weight = neighbor.second;
            if (!visited[next]) {
                double result = dfs(next, target, graph, visited);
                if (result != -1.0)
                    return result * weight;
            }
        }
        return -1.0;
    }

    std::vector<double> calcEquation(
        std::vector<std::vector<std::string>>& equations,
        std::vector<double>& values,
        std::vector<std::vector<std::string>>& queries) {

        // 그래프 구성
        std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> graph;
        for (size_t i = 0; i < equations.size(); ++i) {
            const std::string& A = equations[i][0];
            const std::string& B = equations[i][1];
            double k = values[i];

            graph[A].push_back({B, k});
            graph[B].push_back({A, 1.0 / k});
        }

        // 쿼리 처리
        std::vector<double> results;
        for (const auto& query : queries) {
            const std::string& A = query[0];
            const std::string& B = query[1];
            std::unordered_map<std::string, bool> visited;

            double result = dfs(A, B, graph, visited);
            results.push_back(result);
        }

        return results;
    }
};
