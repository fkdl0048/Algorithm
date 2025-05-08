#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    int temp = routes[0][1];
    
    for (auto a : routes) {
        if (temp < a[0]) {
            answer++;
            temp = a[1];
        }
        
        if (temp >= a[1]) temp = a[1];
    }
    
    return answer;
}