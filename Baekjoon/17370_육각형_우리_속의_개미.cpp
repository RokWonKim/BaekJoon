#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long answer = 0;
bool visit[100][100];
int d[2][3][2] = { {{-1,1}, {1,1}, {0,-1} }, { {0,1},{-1,-1},{1,-1} } };

void dfs(int x, int y, int num, int loc, int pax, int pay) {
    if (num == N+1) {
        if (visit[x][y]) answer++;
        return;
    }
    if (visit[x][y]) return;
    visit[x][y] = true;

    for (int i = 0; i < 3; i++) {
        int nx = x + d[loc][i][0];
        int ny = y + d[loc][i][1];

        if (nx == pax && ny == pay) continue;
        dfs(nx,ny,num+1,!loc,x,y);

    }
    visit[x][y] = false;

}


int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    dfs(50,50,0,0,-1,-1);

    if (N >= 5) cout << answer/3 << '\n';
    else cout << 0 << '\n';

    return 0;
}