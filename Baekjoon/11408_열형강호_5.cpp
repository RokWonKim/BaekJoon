#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int capacity[803][803];
int flow[803][803];
int cost[803][803];

vector<int> arr[803];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    int source = N+M+1;
    int sink = N+M+2;

    for (int i = 1; i <= N; i++) {
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

            cost[i][N+a] = b;
            cost[N+a][i] = -b;
        }
    }

    int ended = N+M+3;
    int answer_cnt = 0;
    int answer_money = 0;
    
    while(1) {
        int parent[ended];
        int dist[ended];
        bool inq[ended];
        

        memset(parent, -1, sizeof(parent));
        memset(inq, false, sizeof(inq));
        fill(dist, dist+ended, INF);

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
                if (capacity[now][next] - flow[now][next] > 0 && dist[next] > dist[now] + cost[now][next] ) {
                    dist[next] = dist[now] + cost[now][next];
                    parent[next] = now;

                    if (!inq[next]) {
                        inq[next] = true;
                        q.push(next);
                    }
                }
            }

        }

        if (parent[sink] == -1) break;
        int amount = INF;
        answer_cnt++;
        

        for (int i = sink; i != source; i = parent[i])
            amount = min(amount, capacity[parent[i]][i] - flow[parent[i]][i] );
        
        for (int i = sink; i != source; i = parent[i]) {
            answer_money += cost[parent[i]][i] * amount; 
            flow[parent[i]][i] += amount;
            flow[i][parent[i]] -= amount;
        }

    }

    cout << answer_cnt << '\n' << answer_money << '\n';

    return 0;
}