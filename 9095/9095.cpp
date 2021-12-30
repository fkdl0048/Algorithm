#include <iostream>

using namespace std;

int main(){
    int t, n;
    int arr[12] = {0};

    cin >> t;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i = 4; i < 12; i++){
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    while(t--){
        cin >> n;
        cout << arr[n] << "\n";
    }

    return 0;
}
