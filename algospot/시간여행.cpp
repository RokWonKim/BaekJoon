#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 987654321;

int V,W;
int past_bellman[100];
int future_bellman[100];
vector< pair<int,int> > plus_arr[100];
vector< pair<int,int> > minus_arr[100];

int solve(int *bellman, vector< pair<int,int> > *arr) {

    for (int i = 0; i < V; i++) {
        bool update = false;

        for(int j = 0; j < V; j++) {
            for(int z= 0; z < arr[j].size(); z++) {
                int next_ver = arr[j][z].first;
                int wei = arr[j][z].second;
                
                if (bellman[j] == INF) continue;
                if (bellman[next_ver] > bellman[j] + wei) {
                    bellman[next_ver] = bellman[j] + wei;
                    update = true;
                }
            }
        }
        if ( i == V-1 && update)
            return INF+1;
    }

    return bellman[1];
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        fill(past_bellman, past_bellman+100, INF);
        past_bellman[0] = 0;
        fill(future_bellman, future_bellman+100, INF);
        future_bellman[0] = 0;

        for (int i = 0; i < 100; i++) {
            plus_arr[i].clear();
            minus_arr[i].clear();
        }
        
        cin >> V >> W;
        for(int i = 0; i < W; i++) {
            int a,b,c;
            cin >> a >> b >>c;
            plus_arr[a].push_back({b,c});
            minus_arr[a].push_back({b,-c});
        }

        int answer = solve(past_bellman , plus_arr);

        if (answer == INF)
            cout << "UNREACHABLE\n";
        else {
            if (answer == INF+1) cout << "INFINITY ";
            else  cout << answer << ' ';

            answer = solve(future_bellman, minus_arr);
            if (answer == INF+1) cout << "INFINITY\n";
            else  cout << -answer << '\n';
        }
        
    }
    return 0;
}