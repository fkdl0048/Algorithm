#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
	int n, len, one;
	while (cin >> n){
		one = 1;
		len = 1;
		while (1){
			if(one % n == 0){
				break;
			}
			else{
				len++;
				one = one * 10 + 1;
				one %= n;
			}
		}
		cout << len << "\n";
	}
	
	return 0;
}