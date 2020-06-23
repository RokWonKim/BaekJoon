#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int N,M;
int arr[201][201];
int aMatch[201];
int bMatch[201];
bool visit[201];

int dfs(int a) {

    if (visit[a]) return false;
    visit[a] = true;

    for (int i = 1; i <= M; i++) {
        if (arr[a][i] == 0) continue;

        if (bMatch[i] == -1 || dfs(bMatch[i])) {
            bMatch[i] = a;
            aMatch[a] = i;
            return true;
        }
    }

    return false;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(aMatch, -1, sizeof(aMatch));
    memset(bMatch, -1, sizeof(bMatch));

    
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

    //한 번에 한 정점씩만 연결해줌
    for (int i = 1; i <= N; i++) {
        memset(visit, false, sizeof(visit));
        if ( dfs(i) ) answer++;
    }

    cout << answer << '\n';
    
    return 0;
}