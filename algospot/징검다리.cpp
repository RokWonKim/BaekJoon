#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    vector<int> diff;
    sort(rocks.begin(), rocks.end());
    
    int left = 1;
    int right = 1*1000*1000*1000;
    
    
    while (left <= right) {
        
        int mid = (left+right) / 2;
        int count = 0;
        int last_rock = -1;
        
        for (int i = 0; i <= rocks.size(); i++) {
            int now;
            if (last_rock == -1)
                now = rocks[i];
            else if (i == rocks.size())
                now = distance - rocks[last_rock];
            else
                now = rocks[i] - rocks[last_rock];
            
            if (now < mid) count++;
            else last_rock = i;
        }
        
        if (count <= n)left = mid + 1;
        else right = mid - 1;
        
    }
    
    return right;
}