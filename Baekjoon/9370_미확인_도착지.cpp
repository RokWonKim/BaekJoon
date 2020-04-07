#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

bool check[2001];
int weight[2001];
vector< pair<int,int> > arr[2001];

void dij(int start) {
    
    memset(weight, 1<<6, sizeof(weight));
    memset(check, false, sizeof(check));

    priority_queue< pair<int,int> > q;
    q.push({0,start});
    weight[start] = 0;

    while(!q.empty()) {
        int vertex = q.top().second;
        int sum_weight = -q.top().first;
        q.pop();

        if (sum_weight > weight[vertex]) continue;

        for (auto a : arr[vertex]) {
            int next_vertex = a.first;
            int next_sum_weight = a.second + sum_weight;
            
            if (next_sum_weight < weight[next_vertex]) {
                weight[next_vertex] = next_sum_weight;
                q.push({-next_sum_weight, next_vertex});
            }
        }
    }
    
}

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int n,m,t;
        int start, g, h;
        int between = 0;

        vector<int> candidate;

        cin >> n >> m >> t;
        cin >> start >> g >> h;

        for (int i = 0; i < m; i++) {
            int a,b,c;
            cin >> a >> b >> c;
            arr[a].push_back({b,c});
            arr[b].push_back({a,c});
            if ( (a == h && b == g) || (a == g && b == h) )
                between = c;
        }
        
        for (int i = 0; i < t; i++) {
            int value;
            cin >> value;
            candidate.push_back(value);
        }
        sort(candidate.begin(), candidate.end());
        
        
        int more_short = h;
        int next = g;
        int all_weight[2001];
        
        dij(start);
        if ( weight[h] > weight[g])
            swap(more_short, next);
        for (int i = 1; i <= n; i++)
            all_weight[i] = weight[i];
        dij(next);
        
        for (int i = 0; i < candidate.size(); i++) {
            int value = candidate[i];
            if (all_weight[value] == between+all_weight[more_short]+weight[value])
                cout << value << ' ';
        }
        
        cout << '\n';
        for(int i = 1; i <= n; i++)
            arr[i].clear();
    }
    return 0;
}
