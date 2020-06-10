#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int V, M, N;
int new_construct[200][200];

void check(int x, int y, int cost) {

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            new_construct[i][j] = min(new_construct[i][j] ,
                min(new_construct[i][x] + new_construct[y][j]+cost ,new_construct[i][y] + new_construct[x][j] + cost));

}

int main(void) {
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        fill(&new_construct[0][0], &new_construct[199][200], INF);
        cin >> V >> M >> N;

        int answer = 0;

        for (int i = 0; i < V; i++) new_construct[i][i] = 0;

        for (int i = 0; i < M; i++) {
            int a,b,c;
            cin >> a >> b >> c;
            
            if(new_construct[a][b] < c) continue;
            new_construct[a][b] = c;
            new_construct[b][a] = c;
        }

        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    new_construct[i][j] = min(new_construct[i][j], new_construct[i][k]+new_construct[k][j]);

        for (int i = 0 ; i < N; i++) {
            int a,b,c;
            cin >> a >> b >> c;
            if (new_construct[a][b] <= c) answer++;
            else check(a,b,c);
        }

        cout << answer << '\n';

    }

    return 0;
}