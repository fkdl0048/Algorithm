#include<vector>
#include<bits/stdc++.h>           
using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    
    q.push({0,0});
    dist[0][0] = 1;
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1 && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return dist[n - 1][m - 1];
}