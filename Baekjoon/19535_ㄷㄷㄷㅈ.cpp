#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>

using namespace std;

vector<int> v[300001];
int me[300001];
int depth[300001];
int d;

long long D;
long long G;

void dfs(int now, int parent) {

    long long n = (long long)v[now].size();
    if (n >= 3)
        G += (n*(n-1)*(n-2))/(3*2*1);

    if (parent != 0) {
        long long a = v[now].size()-1;
        long long b = v[parent].size()-1;
        if ( a != 0 && b != 0) {
            D += a*b;
        }
    }
    
    
    for (int i : v[now]) {
        if (i == parent) continue;
        
        dfs(i,now);
    }
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        me[a]++;
        me[b]++;
    }

    dfs(1,0);

    if (D == G*3) cout << "DUDUDUNGA\n";
    else if (D > G*3) cout << "D\n";
    else cout << "G\n";

    return 0;
}