#include <bits/stdc++.h>
using namespace std;

int a[9];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
    }

    sort(a, a + 9);

    do
    {
        int result = 0;
        for (int i = 0; i < 7; i++)
        {
            result += a[i];
        }
        if (result == 100)
        {
            for (int j = 0; j < 7; j++)
            {
                cout << a[j] << '\n';   
            }
            break;
        }
    } while (next_permutation(a, a+9));
    return 0;
}