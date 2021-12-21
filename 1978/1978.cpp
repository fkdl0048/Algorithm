#include <iostream>

using namespace std;

bool isprim(int num){
	int i = 2;

	if(num <= 1)
		return false;
	while (num > i){
		if(num  % i == 0)
			return false;
		i++;
	}
	return true;
}

int main(){
	int n, m, cnt;

	cnt = 0;
	cin >> n;
	while (n--){
		cin >> m;
		if(isprim(m))
			cnt++;
	}
	cout << cnt;

	return 0;
}