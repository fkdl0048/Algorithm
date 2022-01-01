#include <iostream>
#include <algorithm>

#define MAX 15

using namespace std;

int l,c;
char arr[MAX] = {};
char res[MAX] = {};
bool visited[MAX] = {0};

bool check(){
    int cnt = 0;
    for (int i = 0; i < l; i++){
        if(res[i] == 'a' ||
        res[i] == 'e' ||
        res[i] == 'i' ||
        res[i] == 'o' ||
        res[i] == 'u'){
            cnt++;
        }
    }
    if((cnt >= 1) && (l - cnt >= 2)){
        return true;
    }
    return false;
}

void dfs(int cnt, int num){
    if(cnt == l){
        if(check()){
            for (int i = 0; i < l; i++)
            {
                cout << res[i];
            }
            cout << "\n";
            return;
        }
    }
    for (int i = num; i <= c; i++){
        if(!visited[i]){
            visited[i] = true;
            res[cnt] = arr[i - 1]; 
            dfs(cnt+1, i + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> l >> c;
    for(int i = 0; i < c; i++){
        cin >> arr[i];
    }
    sort(arr, arr+c);
    
    dfs(0, 1);

    return 0;
}