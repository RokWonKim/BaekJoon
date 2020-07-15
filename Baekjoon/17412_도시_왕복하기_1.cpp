#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 401
using namespace std;

int capacity[MAX][MAX];
int flow[MAX][MAX];
vector<int> arr[MAX];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N,P;
    cin >> N >> P;
    int source = 1;
    int sink = 2;

    for (int i = 0; i < P; i++) {
        int a,b;
        cin >> a >> b;

        capacity[a][b] = 1;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    int answer = 0;

    while(1) {
        int parent[N+1];

        memset(parent, -1, sizeof(parent));

        queue<int> q;
        q.push(source);
        parent[source] = source;

        while(!q.empty() && parent[sink] == -1) {
            int now = q.front();
            q.pop();

            for (int next : arr[now]) {
                if(capacity[now][next] - flow[now][next] > 0 && parent[next] == -1) {
                    parent[next] = now;
                    q.push(next);
                }
            }
        }

        if (parent[sink] == -1) break;
        answer++;
        for (int i = sink; i != source; i = parent[i]) {
            flow[parent[i]][i]++;
            flow[i][parent[i]]--;
        }
    }

    cout << answer;

    return 0;
}