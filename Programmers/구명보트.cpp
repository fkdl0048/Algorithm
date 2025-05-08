#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int s = 0;
    int e = people.size() - 1;
    
    sort(people.begin(), people.end());
    
    while (s <= e) {
        if (people[s] + people[e] <= limit) s++;
        
        e--;
        answer++;
    }
    
    return answer;
}