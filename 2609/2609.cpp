#include <iostream>

using namespace std;

int gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd(b , a%b);
}

int main(int argc, char const *argv[]){
	int a,b;
	int result;

	cin >> a >> b;
	
	if(a >= b){
		result = gcd(a,b);
	}
	else{
		result = gcd(b,a);
	}
	cout << result << "\n" << a * b / result << "\n"; 

	return 0;
}