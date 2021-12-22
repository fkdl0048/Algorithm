#include <iostream>

using namespace std;

char arr[51][51];
int total;
int n;

void count();

int main(){
    int i, j;

    total = 1;
    cin >> n;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for (i = 0; i < n; i++){
        for(j = 0; j < n - 1; j++){
            swap(arr[i][j], arr[i][j+1]);
            count();
            swap(arr[i][j], arr[i][j+1]);
        }
    }
    
    for (j = 0; j < n; j++){
        for(i = 0; i < n - 1; i++){
            swap(arr[i][j], arr[i+1][j]);
            count();
            swap(arr[i][j], arr[i+1][j]);
        }
    }
    
    cout << total;
}

void count(){
    char check_char;
    int i, j, cnt;
    
    for(i = 0; i < n; i++){
        cnt = 1;
        check_char = arr[i][0];
        for(j = 1; j < n; j++){
            if(check_char == arr[i][j])
                cnt++;
            else
                cnt = 1;
            check_char = arr[i][j];
            if(cnt > total)
                total = cnt;
        }
    }

    for(j = 0; j < n; j++){
        cnt = 1;
        check_char = arr[0][j];
        for(i = 1; i < n; i++){
            if(check_char == arr[i][j])
                cnt++;
            else
                cnt = 1;
            check_char = arr[i][j];
            if(cnt > total)
                total = cnt;
        }
    }
}