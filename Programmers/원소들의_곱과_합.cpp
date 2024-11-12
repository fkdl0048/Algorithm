#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int multiple = 1;
    int square = 0;
    
    for (int num : num_list) {
        multiple *= num;
        square += num;
    }
    square = square * square;
    
    return square < multiple ? 0 : 1;
}