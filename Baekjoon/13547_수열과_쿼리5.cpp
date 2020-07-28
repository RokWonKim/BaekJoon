#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#define MAX 100001

using namespace std;

int sq;

struct info{
    int index,s,e;
    bool operator<(const info& b) const {
        if (s/sq != b.s/sq) return (s/sq) < (b.s/sq);
        return e < b.e;
    }
};

int arr[MAX];
int q_answer[MAX];
int appear[MAX*10];
vector<info> q;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    sq = sqrt(N);

    for (int i = 1; i <= N; i++) cin >> arr[i];

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        q.push_back({i,a,b});
    }

    sort(q.begin(), q.end());
    int s = q[0].s;
    int e = q[0].e;
    int answer = 0;
    for (int i = s; i <= e; i++) {
        if (appear[arr[i]] == 0) answer++;
        appear[arr[i]]++;
    }
    q_answer[q[0].index] = answer;

    for (int i = 1; i < M; i++) {
        int ns = q[i].s;
        int ne = q[i].e;

        while(s < ns) {
            appear[arr[s]]--;
            if (appear[arr[s]] == 0) answer--;
            s++;
        }
        while(s > ns) {
            --s;
            appear[arr[s]]++;
            if (appear[arr[s]] == 1) answer++;
        }
        while(e < ne) {
            ++e;
            appear[arr[e]]++;
            if (appear[arr[e]] == 1) answer++;
        }
        while(e > ne) {
            appear[arr[e]]--;
            if (appear[arr[e]] == 0) answer--;
            e--;
        }
        q_answer[q[i].index] = answer;
    }

    for (int i = 0; i < M; i++) cout << q_answer[i] << '\n';

    return 0;
}