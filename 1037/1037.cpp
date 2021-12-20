#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]){
	int n_num, i;
	
	cin >> n_num;
	int *arr = new int[n_num];
	
	for(i = 0; i < n_num; i++){
		cin >> arr[i];
	}

	sort(arr, arr+n_num);

	cout << arr[0] * arr[n_num - 1];
	
	return 0;
}