#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long right = 1e18;
    long long left = 1;
    
    while(left <= right) {
        long long mid = (left+right)/2;
        long long num = 0;
        for (int i = 0; i < times.size(); i++)
            num += mid/times[i];
        
        if (num < n) left = mid+1;
        else right = mid-1;
    }
    
    return left;
}