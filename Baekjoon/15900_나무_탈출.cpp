#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[500001];
long long answer;

void dfs(int cnt, int index, int parent) {

    if (v[index].size() == 1 && v[index][0] == parent) 
        answer += (long long)cnt;

    for (int i : v[index]) {
        if (parent != i)
            dfs(cnt+1, i, index);
    }
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(0, 1, 0);

    if ( answer % 2 == 0) cout << "No\n";
    else cout << "Yes\n";

    return 0;
}