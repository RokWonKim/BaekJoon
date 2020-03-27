#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int INF = 2000000000;
int N, M;
vector< pair<int,int> > arr[501];
vector<int> trace[501];
int weight[501];

void dij(int start, int end) {

    priority_queue< pair<int,int> > q;

    for (int i = 0 ; i < N; i++)
        weight[i] = INF;

    weight[start] = 0;
    
    q.push({0,start});
    
    while(!q.empty()) {
        int vertex = q.top().second;
        int sum_value = -q.top().first;
        q.pop(); 

        if (sum_value > weight[vertex]) continue;

        for (auto a : arr[vertex]) {
            int next_vertex = a.first;
            int next_sum_value = a.second + sum_value;

            if ( a.second == -1) continue;

            if (weight[next_vertex] > next_sum_value) {
                weight[next_vertex] = next_sum_value;
                q.push({-next_sum_value, next_vertex});

                trace[next_vertex].clear();
                //현재의 값이 어디서 왔는지를 저장
                // 하나 하나 역추적하여 전부 지워 줄거임
                trace[next_vertex].push_back(vertex);
            }
            else if (weight[next_vertex] == next_sum_value)
                trace[next_vertex].push_back(vertex);

        }

    }
}

void backtrace(int end) {

    queue<int> q;
    q.push(end);

    while(!q.empty()) {
        int now_vertex = q.front();
        q.pop();

        for (auto a : trace[now_vertex]) {
            int before = a;
            q.push(before);

            for(int i = 0; i < arr[before].size(); i++)
                if (arr[before][i].first == now_vertex)
                    arr[before][i].second = -1; 
        }
    }

}

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        int start,end;
        cin >> start >> end;

        for (int i = 0; i < M; i++) {
            int a,b,c;
            cin >> a >> b >> c;
            arr[a].push_back({b,c});
        }

        dij(start, end);
        backtrace(end);
        dij(start,end);

        int ans = weight[end]==INF?-1:weight[end];
        cout << ans << '\n';

        for (int i = 0; i < N; i++) {
            arr[i].clear();
            trace[i].clear();
        }
        
    }

    return 0;
}