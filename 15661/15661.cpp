#include <iostream>
#define MAX 22
using namespace std;

int n;
int ans = 1000000000;
int arr[MAX][MAX] = {0};
bool visited[MAX];

void dfs(int cnt, int num){
	if(cnt == n/2 || cnt == n/2+1){
		int team_start = 0;
		int team_link = 0;
		int temp;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if(visited[i] == true && visited[j] == true)
					team_start += arr[i][j];
				if(visited[i] == false && visited[j] == false)
					team_link += arr[i][j];
			}
		}
		temp = abs(team_start - team_link);
		if(ans > temp)
			ans = temp;

		return;
	}
	for (int i = num; i <= n; i++){
		visited[i] = true;
		dfs(cnt + 1, i + 1);
		visited[i] = false;
	}
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> arr[i][j];
		}
	}
	
	dfs(0, 1);

	cout << ans;

	return 0;
}