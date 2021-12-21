#include <iostream>

using namespace std;
const int MAX = 1000000;

long long ans[MAX];

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int m;
	
	cin >> m;
	for (int i = 1; i <= MAX; i++){
		for (int j = 1; i * j <= MAX; j++)
		{
			ans[i * j] += i;
		}
		ans[i] += ans[i - 1];
	}
	for (int i = 0; i < m; i++){
		int n;
		cin >> n;
		cout << ans[n] << "\n";
	}

	return 0;
}