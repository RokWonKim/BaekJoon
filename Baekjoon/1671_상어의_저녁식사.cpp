#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct info{
    int si;
    int sp;
    int wi;
};

const int INF = 987654321;

int flow[102][102];
int capacity[102][102];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int source = 0;
    int link = 2*N+1;
    int answer = 0;

    vector<info> v;
    v.push_back({0,0,0});
    for (int i = 1; i <= N; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back({a,b,c});
    }

    for (int i = 1; i <= N; i++) {

        capacity[source][i] = 2;
        capacity[i+N][link] = 1;
        for (int j = 1; j <= N; j++) {
            if (v[i].si == v[j].si && v[i].sp == v[j].sp && v[i].wi == v[j].wi) {
                if (i > j) {
                    capacity[i][j+N] = 1;
                } 
            }
            else if (v[i].si >= v[j].si && v[i].sp >= v[j].sp && v[i].wi >= v[j].wi)
                capacity[i][j+N] = 1;
        }
    }

    while(true) {
        vector<int> parent(N*2+2, -1);
        queue<int> q;
        parent[source] = source;
        q.push(0);

        while(!q.empty() && parent[link] == -1) {
            int now = q.front();
            q.pop();

            for (int i = 0; i < N*2+2; i++) {
                if (capacity[now][i]-flow[now][i] > 0 && parent[i] == -1) {
                    q.push(i);
                    parent[i] = now;
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
        answer += amount;
    }

    cout << N-answer << '\n';

    return 0;
}