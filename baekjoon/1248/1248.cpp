#include <iostream>
#define MAX 10

using namespace std;

int n;
char arr[MAX][MAX];
int res[MAX];

bool check(int idx){
	int sum = 0;
	for (int i = idx; i >= 0; i--){
		sum = sum + res[i];
		if(arr[i][idx] == '+' && sum <= 0)
			return false;
		if(arr[i][idx] == '-' && sum >= 0)
			return false;
		if(arr[i][idx] == '0' && sum != 0)
			return false;
	}
	return true;
}

void dfs(int cnt){
	if(cnt == n){
		for (int i = 0; i < cnt; i++){
			cout << res[i] << " ";
		}
		exit(0);
	}
	for (int i = -10; i <= 10; i++){
		res[cnt] = i;
		if(check(cnt) == true)
			dfs(cnt + 1);
	}
	
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			cin >> arr[i][j];
		}
	}
	
	dfs(0);
}