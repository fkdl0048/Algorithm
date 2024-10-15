#include <bits/stdc++.h>

using namespace std;

struct Example {
    char a;   // 1 byte
    int b;    // 4 bytes
    short cc;  // 2 bytes 없어도 같음
    char d;   // 1 byte 없어도 같음
    char c;   // 1 byte
};

int main()
{
    cout << sizeof(Example) << endl; // 12 bytes
}