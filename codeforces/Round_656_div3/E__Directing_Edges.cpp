#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#define MAX 200001

using namespace std;

vector<int> e[MAX];
vector<pair<int,pair<int,int>>> v;
int point[MAX];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N, M;
        cin >> N >> M;

        memset(point, 0, sizeof(point));
        for (int i = 0; i <= N; i++) e[i].clear();
        v.clear();

        for(int i = 0; i < M; i++) {
            int t,x,y;
            cin >> t >> x >> y;

            if (t == 1) {
                e[x].push_back(y);
                point[y]++;
            }
            v.push_back({t,{x,y}});
        }

        queue<int> q;
        vector<int> level(N+1);
        int cnt = 1;

        for (int i = 1; i <= N; i++)
            if (point[i] == 0) q.push(i);

        while(!q.empty()) {
            int now = q.front();
            q.pop();
            level[now] = cnt++;

            for (int next : e[now]) {
                point[next]--;
                if (point[next] == 0) q.push(next);
            }
        }

        bool no = false;
        for (int i = 1; i <= N; i++)
            if (point[i] > 0) no = true;

        if (no) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";

        for (int i = 0; i < v.size(); i++) {
            int t = v[i].first;
            int x = v[i].second.first;
            int y = v[i].second.second;

            if (t == 1)
                cout << x << ' ' << y << '\n';
            else {
                if (level[x] > level[y])
                    cout << y << ' ' << x << '\n';
                else
                    cout << x << ' ' << y << '\n';
            }
        }
    }

    return 0;
}