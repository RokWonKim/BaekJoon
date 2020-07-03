#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 987654321;

int flow[301][301];
int capacity[301][301];
vector<int> e[301];
vector<pair<int,int>> all_e;

int main(void) {
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(flow, 0, sizeof(flow));
        memset(capacity, 0, sizeof(capacity));
        for (int i = 1; i < 301; i++) e[i].clear();
        all_e.clear();

        int N, M;
        cin >> N >> M;
        int source = 1;
        int sink = N;
        int answer = 0;

        for (int i = 0; i < M; i++) {
            int a,b,c;
            cin >> a >> b >> c;
            capacity[a][b] += c;

            e[a].push_back(b);
            e[b].push_back(a);
            all_e.push_back({a,b});
        }

        while(true) {
            vector<int> parent(N+1, -1);
            queue<int> q;
            parent[source] = source;
            q.push(source);

            while(!q.empty() && parent[sink] == -1) {
                int now = q.front();
                q.pop();

                for (int i : e[now]) {
                    if (capacity[now][i] - flow[now][i] > 0 && parent[i] == -1) {
                        parent[i] = now;
                        q.push(i);
                    }
                }
            }

            int amount = INF;
            if (parent[sink] == -1) break;
            

            for (int i = sink; i != source; i = parent[i])
                amount = min(amount, capacity[parent[i]][i] - flow[parent[i]][i]);

            for (int i = sink; i != source; i = parent[i]) {
                flow[parent[i]][i] += amount;
                flow[i][parent[i]] -= amount;
            }
        }

        for (pair<int,int> now : all_e) {
            int part_source = now.first;
            int part_sink = now.second;

            vector<int> parent(N+1,-1);
            queue<int> q;
            parent[part_source] = part_source;
            q.push(part_source);

            while(!q.empty() && parent[part_sink] == -1) {
                int now = q.front();
                q.pop();

                for (int p : e[now]) {
                    if (capacity[now][p] - flow[now][p] > 0 && parent[p] == -1) {
                        parent[p] = now;
                        q.push(p);
                    }
                }
            }

            if (parent[part_sink] == -1) answer++;

        }
        cout << answer << '\n';

    }
    return 0;
}