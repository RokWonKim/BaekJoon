#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N, M;
int parent[2000];
int rank_ver[2000];
vector< pair< int,pair<int,int> > > arr;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (rank_ver[a] < rank_ver[b]) swap(a,b);
    rank_ver[a] += rank_ver[b];
    parent[b] = a;
}


int solve(int limit_low) {
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        rank_ver[i] = 1;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].first < limit_low) continue;

        merge(arr[i].second.first, arr[i].second.second);

        if (find(0) == find (N-1)) return arr[i].first;

    }
    return INF;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    
    cin >> T;
    while(T--) {
        int answer = INF;

        cin >> N >> M;
        arr.clear();

        for(int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            arr.push_back({c, {a,b}});
        }
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++)
            answer = min(answer, solve(arr[i].first) - arr[i].first);

        cout << answer <<'\n';
    }

    return 0;
}