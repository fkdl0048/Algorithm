#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;

int n, m;
bool visited[MAX] = {0};
int arr[MAX] = {0};
int n_arr[MAX] = {0};

void dfs(int cnt, int num){
    if(cnt == m){
        for (int i = 0; i < m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = num; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = n_arr[i - 1];
            dfs(cnt + 1, i + 1);
            visited[i] = false; 
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> n_arr[i];
    }
    sort(n_arr, n_arr+n);
    dfs(0, 1);
}