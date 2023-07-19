#include <iostream>
#define MAX 10
using namespace std;

int n;
int arr[MAX];
bool visited[MAX];

int main()
{   
    cin >> n;
    
    dfs(0);

    return 0;
}