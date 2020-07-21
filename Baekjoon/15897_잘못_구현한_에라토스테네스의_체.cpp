#include <iostream>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    long long N;
    long long answer = 0;
    long long jump = 0;
    cin >> N;
    
    for (long long i = 1; i <= N; i += jump) {
        long long d = (N-1)/i;
        long long m = (N-1)%i;
        
        if ( d == 0 ) jump = 1;
        else jump = m/d +1;

        answer += (d+1)*jump;    
    }
    cout << answer << '\n';

    return 0;
}