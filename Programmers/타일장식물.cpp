#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    if (N == 1)
        return 1;
    vector<long long> v(N+1);
    v[1] = 1;
    for(long long i = 2; i <= N; i++) {
        v[i] = v[i-1] + v[i-2];
    }
    answer = v[N]*2 + (v[N]+v[N-1])*2;
    return answer;
}
