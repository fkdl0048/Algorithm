#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	int n = 0;
	long long total = 0;
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		total += (n / i) * i;
	}
	cout << total << "\n";
	
	return 0;
}