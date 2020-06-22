#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 987654321;

int flow[120][120];
int capacity[120][120];
int arr[12];

int networkflow(int source, int sink) {
    int allflow = 0;

    while(1) {
        vector<int> parent(120,-1);
        queue<int> q;
        parent[source] = source;
        q.push(source);

        while (!q.empty() && parent[sink] == -1) {
            int now = q.front();
            q.pop();

            for (int i = 0; i < 120; i++) {
                if (capacity[now][i] - flow[now][i] > 0 && parent[i] == -1) {
                    q.push(i);
                    parent[i] = now;
                }
            }
        }
        if (parent[sink] == -1) break;

        int amount = INF;
        for (int i = sink; i != source; i = parent[i])
            amount = min(amount, capacity[parent[i]][i] - flow[parent[i]][i]);
        
        for (int i = sink; i != source; i = parent[i]) {
            flow[parent[i]][i] += amount;
            flow[i][parent[i]] -= amount;
        }
        allflow += amount;
    }
    

    return allflow;
}


int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        memset(flow, 0, sizeof(flow));
        memset(capacity, 0, sizeof(capacity));

        int N, M;
        int source = 118;
        int sink = 119;
        int count = 13;
        int allwin = 0;

        cin >> N >> M;
        
        for (int i = 0; i < N; i++) cin >> arr[i];
        
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            
            capacity[source][count] = 1;
            capacity[count][a] = 1;
            capacity[count][b] = 1;
            if ( a== 0 || b == 0) allwin++;
            count++;
        }        

        int value = *max_element(arr,arr+N);
        bool flag = false;
        if(arr[0] != value) value++;
        else {
            for (int i = 1; i < N; i++)
                if (arr[i] == value) {
                    value++;
                    break;
                }
        }
        
        int amount = 0;

        while(value <= arr[0]+allwin) {
            for (int i = 0; i < N; i++) {
                int maxwin = (i == 0 ? value : value-1);
                capacity[i][sink] = maxwin-arr[i];
            }
            amount += networkflow(source, sink);
            if (amount == M) {
                flag = true;
                cout << value << '\n';
                break;
            }
            value++;
        }
        if (!flag) cout << -1 << '\n';

    }

    return 0;
}