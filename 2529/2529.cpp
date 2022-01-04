#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k;
char c[10];
bool visited[10];
vector<string> ans;

bool check(string num){
	for (int i = 0; i < k; i++){
		if(c[i] == '>' || c[i] == '<'){
			if(num[i] < num[i + 1])
				return false;
			if(num[i] > num[i + 1])
				return false;
		}
	}
	return true;
}

void dfs(int cnt, string num){
	if(cnt == k + 1){
		if(check(num))
			ans.push_back(num);
		return;	
	}
	for (int i = 0; i <= 9; i++){
		if(!visited[i]){
			visited[i] = true;
			dfs(cnt + 1, num + to_string(i));
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> k;

	for (int i = 0; i < k; i++){
		cin >> c[i];
	}

	dfs(0,"");
	sort(ans.begin(), ans.end());

	cout << ans[ans.size() - 1] << "\n";
	cout << ans[0];
	
	return 0;
}