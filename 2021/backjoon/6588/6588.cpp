#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define MAX 1000001

using namespace std;

bool check[MAX];
vector<int> prime;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int i, j, n, reslut;

	fill_n(check, MAX, true);
	for (i = 2; i*i < MAX; i++){
		if (check[i] == true){
			for (j = i + i; j < MAX; j += i){
				check[j] = false;
			}
		}
	}
	
	for (i = 2; i < MAX; i++){
		if (check[i] == true)
			prime.push_back(i);
	}
	
	while (true)
	{
		cin >> n;
		if (n == 0)
			break;
		reslut = 0;
		for (i = 1; prime[i] < n; i++){
			reslut = n - prime[i];
			if (check[reslut]){
				cout << n << " = " << prime[i] << " + " << reslut << "\n";
				break;
			}
		}
		if(reslut == 0)
			cout << "Goldbach's conjecture is wrong.\n";
	}
	
	return 0;
}