#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool but[10]; 

int check(int n){
    int cnt;

    if (n == 0){
        if(but[0])
            return 0;
        else
            return 1;
    }
    cnt = 0;
    while(n > 0){
        if(but[n % 10]){
            return 0;
        }
        n /= 10;
        cnt++;
    }   
    return cnt;
}

int main(){
    int i;
    int n, cnt, temp, res, len, mp;

    cin >> n >> cnt;
    for (i = 0; i < cnt; i++){
        cin >> temp;
        but[temp] = true;
    }
    res = abs(n - 100);

    for(i = 0; i <= 1000000; i++){
        len = check(i);
        if(len > 0){
            mp = abs(i - n);
            if(res > mp + len)
                res = mp + len;
        }
    }
    cout << res;
    
    return 0;
}

