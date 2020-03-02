#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, r1, r2;

bool visited[100001];

vector< pair<int, int> > arr[100001];

struct info {
    int vertex;
    int sum;
    int max_value;
};


void BFS() {

    queue< info > q;

    visited[r1] = true;
    q.push({r1,0,0});

    while( !q.empty() ) {

        int v = q.front().vertex;
        int sum = q.front().sum;
        int max_value = q.front().max_value;

        q.pop();

        if (v == r2) {
            cout << sum-max_value;
            break;
        }

        for (int i = 0; i < arr[v].size(); i++) {
            if (visited[arr[v][i].first] == false) {
                visited[arr[v][i].first] = true;
                q.push({arr[v][i].first, sum+arr[v][i].second, max(max_value, arr[v][i].second)});
            }   
        }

    }

    return;
}

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int a,b,c;
    
    cin >> N >> r1 >> r2;

    for (int i = 0; i < N-1; i++) {
        cin >> a >> b >> c;
        arr[a].push_back({b,c});
        arr[b].push_back({a,c});
    }

    BFS();

    return 0;
}