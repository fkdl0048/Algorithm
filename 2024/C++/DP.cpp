#include <iostream>
#include <vector>

using namespace std;

long long fibonacci(int n) {
    if (n <= 1)
        return n;

    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 50; // 예를 들어 50번째 피보나치 수를 구하고자 함

    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;

    return 0;
}
