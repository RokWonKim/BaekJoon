#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

int capacity[801][801];
int flow[801][801];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int source = 1*2;
    int link = 2*2-1;
    int N,P;
    int all_flow = 0;
    cin >> N >> P;
    for (int i = 1; i <= N; i++)
        capacity[i*2-1][i*2] = 1;

    for (int i = 0; i < P; i++) {
        int a, b;
        cin >> a >> b;
        capacity[a*2][b*2-1] = 1;
        capacity[b*2][a*2-1] = 1;
    }

    while(true) {
        vector<int> parent(N*2+1, -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;

        while(!q.empty() && parent[link] == -1) {
            int now = q.front();
            q.pop();

            for (int i = 2; i <= N*2; i++) {
                if (capacity[now][i] - flow[now][i] > 0 && parent[i] == -1) {
                    parent[i] = now;
                    q.push(i);
                }
            }
        }

        if (parent[link] == -1) break;

        int amount = INF;
        for (int i = link; i != source; i = parent[i])
            amount = min(amount, capacity[parent[i]][i] - flow[parent[i]][i]);

        for (int i = link; i != source; i = parent[i]) {
            flow[parent[i]][i] += amount;
            flow[i][parent[i]] -= amount;
        }
        all_flow += amount;

    }

    cout << all_flow << '\n';

    return 0;
}