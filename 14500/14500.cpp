#include <iostream>

using namespace std;

int arr[501][501];
int block[19][3][2] = {
    {{0,1}, {0,2}, {0,3}},
    {{1,0}, {2,0}, {3,0}},
    {{1,0}, {1,1}, {1,2}}, 
    {{0,1}, {1,0}, {2,0}}, 
    {{0,1}, {0,2}, {1,2}}, 
    {{1,0}, {2,0}, {2,-1}}, 
    {{0,1}, {0,2}, {-1,2}}, 
    {{1,0}, {2,0}, {2,1}}, 
    {{0,1}, {0,2}, {1,0}}, 
    {{0,1}, {1,1}, {2,1}}, 
    {{0,1}, {1,0}, {1,1}},  
    {{0,1}, {-1,1}, {-1,2}}, 
    {{1,0}, {1,1}, {2,1}}, 
    {{0,1}, {1,1}, {1,2}}, 
    {{1,0}, {1,-1}, {2,-1}}, 
    {{0,1}, {0,2}, {-1,1}}, 
    {{0,1}, {0,2}, {1,1}}, 
    {{1,0}, {2,0}, {1,1}},
    {{1,0}, {2,0}, {1,-1}},
};

int main(){
    int n,m;
    int res, temp;
    bool check;

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    res = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            for(int k = 0; k < 19; k++){
               check = true;
               temp = arr[i][j];
               for (int l = 0; l < 3; l++){
                   int x = block[k][l][0] + i;
                   int y = block[k][l][1] + j;
                   if((0 <= x && x < n) && (0 <= y && y < m)){
                       temp += arr[x][y];
                   }
                   else{
                       check = false;
                       break;
                   }
               }
               if(check && res < temp){
                   res = temp;
               }
            }
        }
    }
    
    cout << res;

    return 0;
}