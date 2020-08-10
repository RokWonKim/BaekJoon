#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

char arr[101][101];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                arr[i][j] = s[j];
        }

        int answer = 0;
        for (int i = 0; i < n-1; i++)
            if (arr[i][m-1] == 'R') answer++;
        for (int i = 0; i < m-1; i++)
            if (arr[n-1][i] == 'D') answer++;

        cout << answer << '\n';
        
    }
   return 0;
}