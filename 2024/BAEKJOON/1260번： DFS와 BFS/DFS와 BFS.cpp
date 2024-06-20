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

// 그래프의 대표적인 문제로 DFS, BFS 풀이다.
// 정점 N과 간선의 개수 M, 탐색 시작 정점 V
// M개의 줄에 간선을 연결하는 두 정점이 주어짐
// 즉, 정점은 N개로 N이 4라면 1, 2, 3, 4가 존재

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    Node(int n) : n(n) {}
    vector<Node*> next;
    int n;
};

class Graph
{
public:
    Graph(int n, int m) : N(n), M(m) {}

    void makeGraph()
    {
        int x, y;
        nodeV = vector<Node>();

        for (int i = 0; i < N; i++)
        {
            nodeV.push_back(Node(i + 1));
        }
        
        for (int i = 0; i < M; i++)
        {
            cin >> x >> y;
            nodeV[x - 1].next.push_back(&nodeV[y - 1]);
            nodeV[y - 1].next.push_back(&nodeV[x - 1]);
        }

        for (int i = 0; i < N; i++)
        {
            sort(nodeV[i].next.begin(), nodeV[i].next.end(), [](Node* a, Node* b)
            {
                return a->n < b->n;
            });
        }
        
    }

    vector<int> dfs(int v)
    {
        vector<int> result;
        vector<bool> visited(N, false);
        stack<Node*> s;

        s.push(&nodeV[v - 1]);

        while (!s.empty())
        {
            Node* node = s.top();
            s.pop();

            if (!visited[node->n - 1])
            {
                visited[node->n - 1] = true;
                result.push_back(node->n);

                for(auto it = node->next.rbegin(); it != node->next.rend(); ++it)
                {
                    if (!visited[(*it)->n - 1])
                        s.push(*it);
                }
            }
        }

        return result;
    }

    vector<int> bfs(int v)
    {
        vector<int> result;
        vector<bool> visited(N, false);
        queue<Node*> q;

        q.push(&nodeV[v - 1]);
        
        while (!q.empty())
        {
            Node* node = q.front();
            q.pop();

            if (!visited[node->n - 1])
            {
                visited[node->n - 1] = true;
                result.push_back(node->n);
                
                for (const auto nextNode : node->next)
                {
                    if (!visited[nextNode->n - 1])
                        q.push(nextNode);
                }
            }
        }
        
        return result;
    }

private:
    int N;
    int M;
    vector<Node> nodeV;
};


int main(){
    int n, m, v;

    cin >> n >> m >> v;
    Graph graph(n, m);
    graph.makeGraph();

    vector<int> dfsRes = graph.dfs(v);
    vector<int> bfsRes = graph.bfs(v);

    for(const int i : dfsRes)
        cout << i << ' ';
    cout << '\n';

    for(const int i : bfsRes)
        cout << i << ' ';
    cout << '\n';
}