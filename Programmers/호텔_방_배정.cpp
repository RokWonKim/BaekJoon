#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> m;

long long find(long long x) {
    if (m[x] == 0) return m[x] = x+1;
    return m[x] = find(m[x]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    
    vector<long long> ans;
    
    for (int i = 0; i < room_number.size(); i++) {
        long long value = find(room_number[i]);
        ans.push_back(value-1);
    }
    
    return ans;
}