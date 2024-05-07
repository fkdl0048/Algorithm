#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 배열
    // int a[] = {1, 2, 3};
    // do{
    //     for (int i : a) cout << i << ' ';
    //     cout << '\n';
    // }while (next_permutation(a, a + 3));

    // 벡터
    vector<int> a = {21, 2, 3};
    sort(a.begin(), a.end());
    do{
        for (int i : a) cout << i << ' ';
        cout << '\n';
    }while (next_permutation(a.begin(), a.end()));
}

