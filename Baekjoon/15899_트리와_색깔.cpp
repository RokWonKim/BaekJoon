#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200001

using namespace std;

const int MOD = 1*1000*1000*1000+7;

int num;
int color[MAX];
vector<int> v[MAX];
vector<int> tree[MAX*4];

int start_num[MAX];
int end_num[MAX];
int num_color[MAX];

void dfs(int x) {
    start_num[x] = ++num;
    num_color[num] = color[x];
    for (int i : v[x]) {
        if (start_num[i] != 0) continue;
        dfs(i);
    }
    
    end_num[x] = num;
}

void init(int start, int end, int n, int loc) {
    if (n < start || n > end) return;

    tree[loc].push_back( num_color[n]  );
    if (start != end) {
        int mid = (start + end)/2;
        init(start, mid, n, loc*2);
        init(mid+1, end, n, loc*2+1);
    }
}

int q(int start, int end, int a, int b, int c, int loc){
    if (end < a || b < start) return 0;
    else if (a <= start && end <= b) return upper_bound(tree[loc].begin(), tree[loc].end(), c) - tree[loc].begin();
    int mid = (start + end)/2;
    return q(start,mid,a,b,c,loc*2) + q(mid+1,end,a,b,c,loc*2+1);
}


int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N, M, C;
    cin >> N >> M >> C;

    for (int i = 1; i <= N; i++) cin >> color[i];
    for (int i = 0; i < N-1; i++) {
        int a,b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);
    int s = 1;
    int e = N;
    int answer = 0;

    for (int i = 1; i <= N; i++) init(s, e, i, 1);
    for (int i = 1; i < MAX*4; i++)
        if (tree[i].size() > 1) sort(tree[i].begin(), tree[i].end());


    for (int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;
        //cout << q(s, e, start_num[a], end_num[a], b, 1) << '\n';
        answer = ( answer + q(s, e, start_num[a], end_num[a], b, 1) ) % MOD;
    }

    cout << answer << '\n';

    return 0;
}