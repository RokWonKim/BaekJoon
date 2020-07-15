#include <iostream>
#include <cstring>
#include <vector>
#define MAX 1001

using namespace std;

int N,M,K;
int arr[MAX][MAX];
int a[MAX];
int b[MAX];
bool possible[MAX];
bool visit[MAX];

vector<int> e[MAX];

bool dfs(int v) {
    if (visit[v]) return false;
    visit[v] = true;

    for (int next : e[v]) {
        if (b[next] == -1 || dfs(b[next]) ) {
            b[next] = v;
            a[v] = next;
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
    
    cin >> N >> M >> K;
    int answer = 0;
    
    for (int i = 1; i <= N; i++)  {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int next;
            cin >> next;
            arr[i][next] = 1;
            e[i].push_back(next);
        }
    }

    for (int i = 1; i <= N; i++) {
        memset(visit, false, sizeof(visit));
        if (dfs(i)) answer++;
    }

    for (int i = 1; i <= N; i++) {
        while (1) {
            memset(visit, false, sizeof(visit));
            if (dfs(i)) {
                answer++;
                K--;
            }
            else break;

            if (K == 0) break;
        }
        if (K == 0) break;
    }

    cout << answer << '\n';

    return 0;
}