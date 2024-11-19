#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double avg = 0;
    for (int n : numbers) {
        avg += n;
    }
    
    return avg / numbers.size();
}