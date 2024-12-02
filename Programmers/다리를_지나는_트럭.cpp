#include <string>
#include <vector>
#include <queue>

int solution(int bridge_length, int weight, std::vector<int> truck_weights) {
    int time = 0, current_weight = 0;
    std::queue<int> bridge;
    std::queue<int> entry_time;
    
    for (int i = 0; i < bridge_length; i++) {
        bridge.push(0);
    }
    
    int truck_idx = 0;
    while (truck_idx < truck_weights.size() || current_weight > 0) {
        time++;
        
        current_weight -= bridge.front();
        bridge.pop();
        
        if (truck_idx < truck_weights.size() && 
            current_weight + truck_weights[truck_idx] <= weight) {
            bridge.push(truck_weights[truck_idx]);
            current_weight += truck_weights[truck_idx];
            truck_idx++;
        } else {
            bridge.push(0);
        }
    }
    
    return time;
}