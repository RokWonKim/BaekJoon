#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    
    int value = *min_element(cores.begin(), cores.end());
    int start_time = value * (n/cores.size());
    int end_time = value * n;
    
    while(start_time <= end_time) {
        int mid_time = (start_time + end_time)/2;
        int use_core_count = 0;
        int possible_use = 0;
        
        for (int core : cores) {
            use_core_count += mid_time/core;
            
            if (mid_time % core == 0) possible_use++;
            else use_core_count++;
        }
        
        if (use_core_count >= n)
            end_time = mid_time-1;
        else if (use_core_count+possible_use < n)
            start_time = mid_time+1;
        else {
            for (int i = 0; i < cores.size(); i++) {
                if (mid_time % cores[i] == 0) use_core_count++;
                if (use_core_count == n) return i+1;
            }
        }
        
    }
    
    return answer;
}