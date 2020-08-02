#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

int n,s,d;
vector<int> v[100001];
int deep[100001];
int answer;

int dfs(int index, int parent, int depth){

    deep[index] = depth;
    int leaf = depth;
    int end_leaf = depth;

    for (int next : v[index]) {
        if (next == parent) continue;
        leaf = dfs(next, index, depth+1);
        end_leaf = max(leaf,end_leaf);
        if (leaf-depth > d) answer++;
    }

    return end_leaf;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> d;
    for (int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(s,0,0); 
    if (d == 0) cout << (n-1)*2 << '\n';
    else cout << answer*2 <<'\n';

    return 0;
}