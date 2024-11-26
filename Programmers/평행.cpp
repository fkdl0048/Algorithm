#include <string>
#include <vector>

using namespace std;

double calculateSlope(const vector<int>& point1, const vector<int>& point2) {
    return static_cast<double>(point2[1] - point1[1]) / (point2[0] - point1[0]);
}

int solution(vector<vector<int>> dots) {
    if (calculateSlope(dots[0], dots[1]) == calculateSlope(dots[2], dots[3])) return 1;
    if (calculateSlope(dots[0], dots[2]) == calculateSlope(dots[1], dots[3])) return 1;
    if (calculateSlope(dots[0], dots[3]) == calculateSlope(dots[1], dots[2])) return 1;

    return 0;
}