#include <iostream>
#define MAX 10
using namespace std;

int n;
int arr[MAX];
bool visited[MAX];

void dfs(int cnt)
{
    if(n == cnt)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            arr[cnt] = i;
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{   
    cin >> n;
    
    dfs(0);

    return 0;
}