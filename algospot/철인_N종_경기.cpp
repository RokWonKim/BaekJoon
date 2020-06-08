#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int ST = 401;

vector< pair<int,int> > arr[402];
vector< pair<int,int> > a_b;

int wei[402];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(wei, -1, sizeof(wei));
        for(int i = 0; i < 402; i++) arr[i].clear();
        a_b.clear();

        int M, count = 0;
        cin >> M;
        for(int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a_b.push_back({a,b});
            if (a < b) count++;

            int value = a-b;
            arr[ST].push_back({value+200, a});
        }

        if ( count == 0 || count == M) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        for (int i = -200; i <= 200; i++) {
            for (int j = 0; j < a_b.size(); j++) {
                int value = (a_b[j].first-a_b[j].second) + i;
                if (value > 200 || value < -200) continue;

                arr[i+200].push_back({value + 200, a_b[j].first});
            }
        }

        int answer = 0;
        priority_queue< pair<int,int> > q;
        q.push({0, ST});
        while(!q.empty()) {
            int now = -q.top().first;
            int ver = q.top().second;
            q.pop();

            if (wei[ver] != -1) continue;
            wei[ver] = now;

            if (ver == 200) {
                answer = now;
                break;
            }
            
            for (pair<int,int>& next : arr[ver])
                q.push({-(now + next.second), next.first});
        }

        cout << answer << '\n';

    }
    return 0;
}