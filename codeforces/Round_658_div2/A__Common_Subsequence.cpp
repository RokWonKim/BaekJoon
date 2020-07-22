#include <iostream>
#include <cstring>

using namespace std;

bool check[1001];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(check, false, sizeof(check));

        int N, M;
        int answer = -1;
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            int v;
            cin >> v;
            check[v] = true;
        }

        for (int i = 0; i < M; i++) {
            int v;
            cin >> v;
            if (check[v]) answer = v;
        }

        if (answer == -1) cout << "NO\n";
        else {
            cout << "YES\n";
            cout << 1 << ' ' << answer << '\n';
        }

    }


    return 0;
}