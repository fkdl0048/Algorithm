#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, m, i, j;
	bool *prime;

	cin >> n >> m;
	prime = new bool[m + 1];
	fill_n(prime, m+1, 1);
	prime[0] = false;
	prime[1] = false;	

	for (i = 2; i <= sqrt(m); i++){
		if(prime[i] == true){
			for (j = i * 2; j <= m; j += i){
				prime[j] = false;
			}
		}
	}

	for (i = n; i <= m; i++){
		if(prime[i] == true){
			cout << i << "\n";
		}
	}

	return 0;
}