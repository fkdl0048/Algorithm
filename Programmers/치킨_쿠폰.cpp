#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int service_chicken = 0;
    int coupons = chicken;
    
    while(coupons >= 10) {
        int new_chicken = coupons / 10;
        int remaining_coupons = coupons % 10;
        
        service_chicken += new_chicken;
        coupons = new_chicken + remaining_coupons; 
    }
    
    return service_chicken;
}