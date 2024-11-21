#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int width = 0;
    int height = 0;

    int min_x = dots[0][0];
    int max_x = dots[0][0];
    int min_y = dots[0][1];
    int max_y = dots[0][1];
    
    for(int i = 1; i < dots.size(); i++) {
        min_x = min(min_x, dots[i][0]);
        max_x = max(max_x, dots[i][0]);
        min_y = min(min_y, dots[i][1]);
        max_y = max(max_y, dots[i][1]);
    }
    
    width = max_x - min_x;
    height = max_y - min_y;
    
    return width * height;
}