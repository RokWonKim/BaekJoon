
#include <iostream>
#include <cstring>

using namespace std;

int N,M;
bool visit[1001];
int a[1001];
int b[1001];
int arr[1001][1001];

bool dfs(int u){
    
    if (visit[u]) return false;
    visit[u] = true;

    for (int i = 1; i <= M; i++) {
        if (arr[u][i] == 0) continue;
        if (b[i] == -1 || dfs(b[i]) ) {
            b[i] = u;
            a[u] = i;
            return true;
        }
    }

    return false;
}

int main(void) {
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    
    memset(a, -1, sizeof(a));
    memset(b, -1, sizeof(b));

    int answer = 0;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int num;
            cin >> num;
            arr[i][num] = 1;
        }
    }

    for(int i = 1; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            memset(visit, false, sizeof(visit));
            if ( dfs(i) ) answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}