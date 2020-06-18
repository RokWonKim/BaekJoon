#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;

//용량
int capacity[256][256];
//유량
int flow[256][256];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    int all_flow = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char a,b;
        int c;
        cin >> a >> b >> c;
        capacity[a][b] += c;
        capacity[b][a] += c;
    }

    while(true){
        queue<int> q;
        vector<int> parent(256, -1);
        q.push('A');
        parent['A'] = 0;

        //q가 비지 않았고 끝에 도달하지 않앗으면 계속 지속
        while(!q.empty() && parent['Z'] == -1) {
            int now = q.front();
            q.pop();

            for (int i = 0; i < 256; i++) {
                //수용력이 있는지
                if ( capacity[now][i]-flow[now][i] > 0 && parent[i] == -1) {
                    q.push(i);
                    parent[i] = now;
                }
            }
        }

        if(parent['Z'] == -1) break;
        
        int amount = INF;
        for (int i = 'Z'; i != 'A'; i = parent[i])
            amount = min(amount, capacity[parent[i]][i] - flow[parent[i]][i]);
        
        for (int i = 'Z'; i != 'A'; i = parent[i]) {
            flow[parent[i]][i] += amount;
            flow[i][parent[i]] -= amount;
        }
        all_flow += amount;

    }
    cout << all_flow << '\n';

    return 0;
}