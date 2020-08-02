#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#define MAX 100001

using namespace std;

int n,m;
int p[MAX];
int h[MAX];

vector<int> v[MAX];
bool visit[MAX];
int me[MAX];

int g[100001];
int b[100001];

bool bip(int index) {
    int bad = b[index];
    int good = g[index];
    int hd = h[index];

    int l = 0;
    int r = bad;

    while(l <= r) {
        int mid = (l+r)/2;
        int part = (good+mid) - (bad-mid);

        if (part == hd) {
            b[index] = bad-mid;
            g[index] = good+mid;
            return true;
        }
        else if (part > hd) r = mid-1;
        else l = mid+1;
    }

    return false;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        for (int i = 1; i < MAX; i++) v[i].clear();
        memset(visit, false, sizeof(visit));
        memset(me, 0, sizeof(me));
        memset(g, 0, sizeof(g));
        memset(b, 0, sizeof(b));

        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) cin >> h[i];

        for (int i = 0; i < n-1; i++) {
            int a,c;
            cin >> a >> c;

            v[a].push_back(c);
            v[c].push_back(a);

            me[a]++;
            me[c]++;
        }

        queue<int> q;
        for (int i = 2; i <= n; i++)
            if (me[i] == 1)
                q.push(i);


        bool answer = true;
        while(!q.empty()) {
            int index = q.front();
            q.pop();

            if (visit[index]) continue;
            visit[index] = true;

            b[index] += p[index];
            if (!bip(index)) {
                answer = false;
                break;
            }

            for (int next : v[index]) {
                if (visit[next]) continue;
                me[next]--;
                g[next] += g[index];
                b[next] += b[index];

                if (next != 1 && me[next] == 1) q.push(next);
            }
        }
        
        if (answer) {
            b[1] += p[1];
            if (!bip(1)) answer = false;
        }

        if (answer) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}