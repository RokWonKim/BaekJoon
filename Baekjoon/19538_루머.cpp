#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>

using namespace std;

vector<int> v[200001];

//내 주변 감염인간 수
//감염인간 수가 size/2보다 같거나 많을때 q에 넣음
int me[200001];

//자신이 감연된 시간
int answer[200001];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(answer, -1, sizeof(answer));

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        while(1) {
            int num;
            cin >> num;
            if (num == 0) break;
            v[i].push_back(num);
        }
    }

    int M;
    cin >> M;
    queue<pair<int,int>>q;

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        q.push({num,0});
    }

    while(!q.empty()) {
        int now = q.front().first;
        int time = q.front().second;
        q.pop();

        if (answer[now] != -1) continue;
        answer[now] = time;

        for (int i : v[now]) {
            me[i]++;
            if (me[i]*2 >= v[i].size() ) q.push({i,time+1});
        }
    }

    for (int i = 1; i <= N; i++) cout <<answer[i] << ' ';
    cout << '\n';

    return 0;
}