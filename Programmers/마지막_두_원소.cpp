#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int num = 0;
    int n = num_list.size();
    num = num_list[n - 2] < num_list[n - 1] ? num_list[n - 1] - num_list[n - 2] : num_list[n - 1] * 2; 
    num_list.push_back(num);
    return num_list;
}