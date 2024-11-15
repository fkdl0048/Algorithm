#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    vector<pair<int, int>> students;
    
    for (int i = 0; i < rank.size(); i++) {
        if (attendance[i]) {
            students.push_back({rank[i], i});
        }
    }
    
    sort(students.begin(), students.end());
    
    return  students[0].second * 10000 +
            students[1].second * 100 +
            students[2].second;
}