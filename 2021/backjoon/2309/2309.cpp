#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int arr[9];
    int i, j, k, sum;

    sum = 0;
    for(i = 0; i < 9; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    
    sort(arr,arr+9);

    for (i = 0; i < 8; i++){
        for (j = i + 1; j < 9; j++){
            if(sum - (arr[i] + arr[j]) == 100){
                for (k = 0; k < 9; k++){
                    if(k != i && k != j){
                        cout << arr[k] << "\n";
                    }
                }
                return 0;
            }
        }
    }

    return 0;
}