/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1260                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1260                           #+#        #+#      #+#    */
/*   Solved: 2024/06/11 01:02:51 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int start) {
    stack<int> s;
    s.push(start);
    visited[start] = true;
    cout << start << " ";

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        for (int i = 0; i < graph[current].size(); ++i) {
            int next = graph[current][i];
            if (!visited[next]) {
                cout << next << " ";
                visited[next] = true;
                s.push(current);
                s.push(next);
                break;
            }
        }
    }
}

void bfs(vector<vector<int>>& graph, vector<bool>& visited, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 0; i < graph[current].size(); ++i) {
            int next = graph[current][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(graph, visited, v);
    cout << endl;

    fill(visited.begin(), visited.end(), false);
    bfs(graph, visited, v);
    cout << endl;

    return 0;
}