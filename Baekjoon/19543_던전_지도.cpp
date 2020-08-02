#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int N,M,K;
string s[26];
//U의 위치
vector<int> v[26];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < K; i++)
        cin >> s[i];

    string a;
    cin >> a;

    for (int i = 0; i < K; i++) {
        v[i].push_back(-1);
        for (int j = 0; j < M; j++) {
            if (s[i][j] == 'U') v[i].push_back(j);
        }
        v[i].push_back(M);
    }


    int start = M-1;
    int end = M-1;
    long long answer = 0;
    for (int i = M-2; i >= 0; i--) {
        if ( s[a[N-1]-'A' ][i] == 'R') start = i;
        else break;
    }

    answer = end-start+1;
    for (int i = N-2; i >=0; i--) {
        int next = a[i]-'A';

        int next_start = lower_bound(v[next].begin(), v[next].end(), start) - v[next].begin();
        int next_end = lower_bound(v[next].begin(), v[next].end(), end) - v[next].begin();

        if (next_start != 0) next_start--;
        if (v[next][next_end] > end) next_end--;

        if (next_start == 0 && next_end == 0) break;
        else
            answer += (v[next][next_end] - v[next][next_start]);

        start = v[next][next_start]+1;
        end = v[next][next_end];
    }

    cout << answer << '\n';

    return 0;
}