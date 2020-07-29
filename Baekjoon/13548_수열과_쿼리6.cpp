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
int answer;
int arr[MAX];
int q_answer[MAX];
int num_count[MAX];
int all_count[MAX];
vector<info> q;

void p(int value) {
    if (num_count[value] != 0) all_count[num_count[value]]--;
    num_count[value]++;
    all_count[num_count[value]]++;
    answer = max(answer, num_count[value]);
}

void m(int value) {
    all_count[num_count[value]]--;
    if (num_count[value] == answer && all_count[num_count[value]] == 0) answer--;

    num_count[value]--;
    all_count[num_count[value]]++;
}

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
    
    for (int i = s; i <= e; i++) p(arr[i]);
    q_answer[q[0].index] = answer;
    
    for (int i = 1; i < M; i++) {
        int ns = q[i].s;
        int ne = q[i].e;
        while(s < ns) {
            m(arr[s]);
            s++;
        }
        while(s > ns) {
            --s;
            p(arr[s]);
        }
        while(e < ne) {
            ++e;
            p(arr[e]);
        }
        while(e > ne) {
            m(arr[e]);
            e--;
        }
        q_answer[q[i].index] = answer;
    }

    for (int i = 0; i < M; i++) cout << q_answer[i] << '\n';

    return 0;
}