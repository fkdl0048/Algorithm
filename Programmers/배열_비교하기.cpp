#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int answer = 0;
    
    if (arr1.size() > arr2.size()) {
        return 1;
    } else if (arr1.size() < arr2.size()) {
        return -1;
    } else {
        int arr1Total = 0;
        int arr2Total = 0;
        for (const auto& n : arr1) {
            arr1Total += n;
        }
        for (const auto& n : arr2) {
            arr2Total += n;
        }
        
        if (arr1Total > arr2Total) {
            return 1;
        } else if (arr1Total < arr2Total) {
            return -1;
        } else {
            return 0;
        }
    }
    return answer;
}