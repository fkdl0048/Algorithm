#include <string>

using namespace std;

int solution(string A, string B) {
    // 문자열이 같으면 밀 필요가 없음
    if(A == B) return 0;
    
    int len = A.length();
    string current = A;
    
    // 최대 len번 밀어보기
    for(int i = 1; i <= len; i++) {
        // 마지막 문자를 저장
        char last = current[len-1];
        
        // 나머지 문자들을 오른쪽으로 한 칸씩 이동
        for(int j = len-1; j > 0; j--) {
            current[j] = current[j-1];
        }
        
        // 마지막 문자를 맨 앞으로
        current[0] = last;
        
        // B와 같아졌다면 현재까지 민 횟수 반환
        if(current == B) {
            return i;
        }
    }
    
    // len번을 밀어도 B가 되지 않으면 불가능
    return -1;
}