#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int incre_num;
int ver_num[100001];
vector<int> arr[100001];
set<pair<int,int>> s;

int bi_com(int now, int prev) {
    int ret = ver_num[now] = ++incre_num;
    int child_num = 0;

    for (int next : arr[now]) {
        if (prev == next) continue;
        if (ver_num[next] == 0) {
            int child = bi_com(next, now);
            if (child > ver_num[now]) {
                if (now < next) s.insert({now,next});
                else s.insert({next,now});
            }
            ret = min(ret, child);
        }
        else
            ret = min(ret, ver_num[next]);
    }

    return ret;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;

        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
        if (ver_num[i] == 0) bi_com(i, -1);

    cout << s.size() << '\n';
    set<pair<int,int>>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter)
        cout << (*iter).first << ' ' << (*iter).second << '\n';

    return 0;
}