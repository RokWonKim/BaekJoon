#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

vector< pair<int,int> > capacity[2002];
int flow[2002][2002];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int process = 0;
    cin >> N >> M;

    int source = 0;
    int link = N+M+1;
    
    
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        capacity[source].push_back({i,1});
        capacity[i].push_back({source,1});

        for (int j =0; j < a; j++) {
            int b; 
            cin >> b;
            capacity[i].push_back({N+b,1});
            capacity[N+b].push_back({i,1});

            capacity[N+b].push_back({link,1});
            capacity[link].push_back({N+b,1});
        }
    }

    while(true) {
        vector<int> parent(N+M+2, -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;

        while(!q.empty() && parent[link] == -1) {
            int now = q.front();
            q.pop();

            for (pair<int,int>& next : capacity[now]) {
                if (next.second - flow[now][next.first] > 0 && parent[next.first] == -1) {
                    q.push(next.first);
                    parent[next.first] = now;
                }
            }
        }

        if (parent[link] == -1) break;

        int amount = INF;
        for (int i = link; i != source; i = parent[i])
            amount = min(amount, 1 - flow[parent[i]][i]);

        for (int i = link; i != source; i = parent[i]) {
            flow[parent[i]][i] += amount;
            flow[i][parent[i]] -= amount;
        }

        process += amount;
    }

    cout << process << '\n';

    return 0;
}