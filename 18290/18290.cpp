#include <iostream>
#define MAX 10
using namespace std;

int n, m, k;
int ans = -210000000;
int n_arr[MAX][MAX] = {0};
bool visited[MAX][MAX] = {0};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int cnt, int sum){
    if (cnt == k) {
        if (ans < sum) ans = sum;
        return;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(visited[i][j])
                continue;
            bool ok = true;
            for (int z = 0; z < 4; z++){
                int nx = i + dx[z];
                int ny = j + dy[z];
                if((nx >= 0 && nx < n) && (ny >= 0 && ny < m)){
                    if(visited[nx][ny]){
                        ok = false;
                    }
                }
            }
            if(ok){
                visited[i][j] = true;
                dfs(cnt + 1, sum + n_arr[i][j]);
                visited[i][j] = false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> n_arr[i][j];
        }
    }
    dfs(0, 0);

    cout << ans;
}