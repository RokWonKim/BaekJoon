#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int arr[101][101];
bool visit[101];
int a[101];
int b[101];

bool dfs(int x) {
    if (visit[x]) return false;
    visit[x] = true;

    for (int i = 1; i <= N; i++) {
        if (arr[x][i] == 0) continue;
        if (b[i] == -1 || dfs( b[i] ) ) {
            b[i] = x;
            a[x] = i;
            return true;
        }
    }
    return false;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(b, -1, sizeof(b));
    memset(a, -1, sizeof(a));

    int answer = 0;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1;
    }

    for (int i = 1; i <= N; i++) {
        memset(visit, false, sizeof(visit));
        if (dfs(i)) answer++;
    }

    cout << answer;

    return 0;
}