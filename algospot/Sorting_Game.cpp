#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> arr;
vector<int> last;
map< vector<int>,int> m[9];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int u = 1; u <= 8; u++) {
        arr.push_back(u);

        queue<vector<int> > q;
        q.push(arr);
        m[u][arr] = 1;

        while(!q.empty()) {
            vector<int> now = q.front();
            int num = m[u][now];
            q.pop();

            for (int i = 0; i < u-1; i++) {
                for (int j = i+1; j < u; j++) {
                    reverse(now.begin()+i, now.begin()+j+1);
                    if (m[u][now] == 0) {

                        m[u][now] = num+1;
                        q.push(now);
                    }
                    reverse(now.begin()+i, now.begin()+j+1);
                }
            }
        }
    }

    int T;
    cin >> T;
    while(T--) {
        last.clear();

        int N;
        cin >> N;
        
        for(int i = 0; i < N; i++) {
            int a;
            cin >> a;
            last.push_back(a);
        }
        bool check[8] = {false, };
        for (int i = 0; i < N; i++) {
            int index;
            int value = 1000001;
            for (int j = 0; j < N; j++) {
                if (!check[j] && last[j] < value) {
                    index = j;
                    value = last[j];
                }
            }
            last[index] = i+1;
            check[index] = true;
        }

        cout << m[N][last]-1 << '\n';
    }

    return 0;
}