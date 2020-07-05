#include <iostream>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

int arr[1001];
int appear[1001];
bool inqueue[1001];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(appear, false, sizeof(appear));
        memset(inqueue, false, sizeof(inqueue));

        int N;
        int num = 0;
        vector<int> answer;
        priority_queue<int> q;
        set<int> big_num;

        cin >> N;

        for (int i = 0; i < N; i++) big_num.insert(i);

        
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            appear[arr[i]]++;
        }

        for (int i = 0; i <= N; i++)
            if (appear[i] == 0)
                q.push(-i);

        while(!big_num.empty()) {
            int now = -q.top();
            q.pop();

            if (appear[now]) continue;
            num++;

            if (now == N) {
                auto a = big_num.end();
                a--;
                int v = *a;

                q.push(-arr[v]);
                appear[arr[v]]--;

                arr[v] = now;
                appear[now]++;

                answer.push_back(v+1);
            }
            else {
                q.push(-arr[now]);
                appear[arr[now]]--;

                arr[now] = now;
                appear[now]++;

                big_num.erase(now);
                answer.push_back(now+1);
            }
        }

        cout << num << '\n';
        for (int v : answer) cout << v << ' ';
        cout << '\n';
    }

    return 0;
}