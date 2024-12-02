#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Job {
    int start;
    int length;
    int index;
    
    Job(int s, int l, int i) : start(s), length(l), index(i) {}
};

struct CompareJob {
    bool operator()(const Job& a, const Job& b) {
        if (a.length != b.length) return a.length > b.length;
        if (a.start != b.start) return a.start > b.start;
        return a.index > b.index;
    }
};

int solution(vector<vector<int>> jobs) {
    vector<Job> job_list;
    for (int i = 0; i < jobs.size(); i++) {
        job_list.push_back(Job(jobs[i][0], jobs[i][1], i));
    }
    sort(job_list.begin(), job_list.end(), 
         [](const Job& a, const Job& b) { return a.start < b.start; });
    
    priority_queue<Job, vector<Job>, CompareJob> waiting_queue;
    int current_time = 0;
    int total_turnaround = 0;
    int job_index = 0;
    
    while (job_index < jobs.size() || !waiting_queue.empty()) {
        // 현재 시점까지 요청된 모든 작업을 대기 큐에 추가
        while (job_index < jobs.size() && job_list[job_index].start <= current_time) {
            waiting_queue.push(job_list[job_index]);
            job_index++;
        }
        
        if (waiting_queue.empty()) {
            // 대기 큐가 비어있다면 다음 작업의 시작 시간으로 이동
            current_time = job_list[job_index].start;
            continue;
        }
        
        // 우선순위가 가장 높은 작업 실행
        Job current_job = waiting_queue.top();
        waiting_queue.pop();
        
        // 작업 완료 및 반환 시간 계산
        current_time += current_job.length;
        total_turnaround += current_time - current_job.start;
    }
    
    return total_turnaround / jobs.size();
}