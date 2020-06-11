#include <iostream>
#include <queue>
#include <vector> 
#include <string>
#include <algorithm>

using namespace std;

int calc_ver(int num, int plus, int mod) {
    int next = num*10 +plus;
    if (mod <= next) return mod + next%mod;
    return next % mod;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        string s;
        int N, M;
        int start = 0;
        
        cin >> s >> N >> M;

        sort(s.begin(), s.end());

        queue<int> q;
        vector<int> arr(2*N, -1), trace(2*N, -1);
        
        trace[0] = 0;
        q.push(start);
        while(!q.empty()) {
            int now = q.front();
            q.pop();
           
            for (int i = 0; i < s.size(); i++) {
                int next = calc_ver(now, s[i]-'0', N);
                if (arr[next] == -1) {
                    arr[next] = s[i]-'0';
                    trace[next] = now;
                    q.push(next);
                }
            }
        }

        if (trace[N+M] == -1) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        string answer = "";
        int now = N+M;
        while(now) {
            answer += char(arr[now]+'0');
            now = trace[now];
        }
        reverse(answer.begin(), answer.end());
        cout << answer << '\n';

    }

    return 0;
}