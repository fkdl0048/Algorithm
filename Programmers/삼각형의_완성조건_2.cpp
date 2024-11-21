#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    int longer = max(sides[0], sides[1]);
    int shorter = min(sides[0], sides[1]);
    
    answer += longer - (longer - shorter);
    
    answer += (shorter + longer) - longer - 1;
    
    return answer;
}