#include <iostream>

using namespace std;

int main()
{
    int n, ans, i;
    cin >> n;

    ans = 0;
    i = 1;
    while(i <= n){
        ans += (n-i+1);
        i *= 10;
    }
    cout << ans;

    return 0;
}