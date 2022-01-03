#include <iostream>
#include <algorithm>

#define MAX 16
using namespace std;

int n;
int t[MAX];
int p[MAX];
int ans;

void dfs(int cnt, int temp){
	if(cnt == n + 1){
		ans = max(ans, temp);
		return;
	}
	if(cnt + t[cnt] <= n + 1)
		dfs(cnt + t[cnt],temp + p[cnt]);
	if(cnt <= n)
		dfs(cnt + 1, temp);
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> t[i] >> p[i];
	}

	dfs(1,0);
	
	cout << ans;

	return 0;
}