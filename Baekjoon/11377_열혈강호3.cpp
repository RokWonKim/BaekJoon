#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N,M,K;
int a[1001];
int b[1001];
vector<int> arr[1001];
bool visit[1001];

bool dfs(int x) {
    if (visit[x]) return false;
    visit[x] = true;

    for (int i : arr[x]) {
        if (b[i] == -1 || dfs(b[i])) {
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

    memset(a, -1, sizeof(a));
    memset(b, -1, sizeof(b));

    int answer = 0;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int next;
            cin >> next;
            arr[i].push_back(next);
        }
    }

    for (int i = 1; i <= N; i++) {
        memset(visit, false, sizeof(visit));
        if ( dfs(i) ) answer++;
    }

    for (int i = 1; i <= N && K > 0; i++) {
        memset(visit, false, sizeof(visit));
        if ( dfs(i) ) {
            answer++;
            K--;
        }
    }

    cout << answer;

    return 0;
}