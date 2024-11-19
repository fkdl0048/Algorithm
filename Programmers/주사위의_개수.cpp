#include <string>
#include <vector>

using namespace std;

int solution(vector<int> box, int n) {
    return (box[0]/n) * (box[1]/n) * (box[2]/n);
}