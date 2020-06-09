#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 987654321;

int floyd[501][501];
int passed[501][501];
vector< pair<int,int> > arr;

int main(void) {
    fill(&floyd[0][0], &floyd[500][501], INF);
    fill(&passed[0][0], &passed[500][501], INF);
    
    int N, M, T, wei;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &wei);
        arr.push_back({wei, i});
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < M; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);

        floyd[a][b] = c;
        floyd[b][a] = c;
        passed[a][b] = c;
        passed[b][a] = c;
    }

    for (int i = 1; i <= N; i++) {
        floyd[i][i] = 0;
        passed[i][i] = 0;
    }

    for (int k = 1; k <= N; k++) {
        int w = arr[k-1].second;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                floyd[i][j] = min(floyd[i][j], floyd[i][w] + floyd[w][j]);
                passed[i][j] = min(floyd[i][j]+ arr[k-1].first, passed[i][j]);   
            }
        }
    }

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        printf("%d\n", passed[a][b] );
    }

    return 0;
}