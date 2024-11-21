#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    if (M == 1 && N == 1) {
        return 1;
    }
    
    return M * N - 1;
}