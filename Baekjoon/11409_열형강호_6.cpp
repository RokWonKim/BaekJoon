#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 803

using namespace std;

const int INF = 987654321;

int capacity[MAX][MAX];
int flow[MAX][MAX];
int cost[MAX][MAX];
vector<int> arr[MAX];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    int source = N+M+1;
    int sink = N+M+2;
    int ended = N+M+3;

    for (int i=1; i <= N; i++) {
        capacity[source][i] = 1;
        arr[source].push_back(i);
        arr[i].push_back(source);
    }
    for (int i = N+1; i <= N+M; i++) {
        capacity[i][sink] = 1;
        arr[sink].push_back(i);
        arr[i].push_back(sink);
    }

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;

        for (int j = 0; j < num; j++) {
            int a,b;
            cin >> a >> b;

            capacity[i][N+a] = 1;

            arr[i].push_back(N+a);
            arr[N+a].push_back(i);

            cost[i][N+a] = -b;
            cost[N+a][i] = b;
        }
    }

    int answer_cnt = 0;
    int answer_money = 0;

    while(1) {
        int parent[ended];
        int dist[ended];
        bool inq[ended];

        memset(parent, -1, sizeof(parent));
        fill(dist,dist+ended,INF);
        memset(inq, false, sizeof(inq));

        queue<int> q;
        q.push(source);
        parent[source] = source;
        dist[source] = 0;
        inq[source] = true;

        while(!q.empty()) {
            int now = q.front();
            q.pop();
            inq[now] = false;
            
            for (int next : arr[now]) {
                if (capacity[now][next]-flow[now][next] > 0 &&
                    dist[next] > dist[now] + cost[now][next]) {
                    parent[next] = now;
                    dist[next] = dist[now] + cost[now][next];
                    if (!inq[next]) {
                        inq[next] = true;
                        q.push(next);
                    }
                }
            }

        }

        if (parent[sink] == -1) break;
        answer_cnt++;

        for (int i = sink; i != source; i = parent[i]) {
            answer_money += cost[parent[i]][i];
            flow[parent[i]][i] += 1;
            flow[i][parent[i]] -= 1;
        }

    }

    cout << answer_cnt << '\n' << -answer_money << '\n';

    return 0;
}