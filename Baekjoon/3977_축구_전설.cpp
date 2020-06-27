#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int incre_num;
int scc_num;
int ver_num[100000];
int sccid[100000];
vector<int> arr[100000];
vector<int> group[100000];
stack<int> st;

int make_scc(int index) {
    int ret = ver_num[index] = incre_num++;
    st.push(index);

    for (int next : arr[index]) {
        if (ver_num[next] == -1)
            ret = min(ret, make_scc(next));
        else if (sccid[next] == -1)
            ret = min(ret, ver_num[next]);
    }

    if (ret == ver_num[index]) {
        while(1) {
            int top = st.top();
            st.pop();

            sccid[top] = scc_num;
            group[scc_num].push_back(top);

            if (index == top) break;
        }
        scc_num++;
    }

    return ret;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N, M;
        cin >> N >> M;

        incre_num = 0;
        scc_num = 0;
        memset(sccid, -1, sizeof(sccid));
        memset(ver_num, -1, sizeof(ver_num));
        for (int i = 0; i < N; i++) {
            arr[i].clear();
            group[i].clear();
        }

        for (int i = 0; i < M; i++) {
            int a,b;
            cin >> a >> b;
            arr[a].push_back(b);
        }

        for(int i = 0; i < N; i++)
            if (sccid[i] == -1)
                make_scc(i);
        
        vector<int> rec_num(scc_num, 0);
        for(int i = 0; i < scc_num; i++)
            for (int now : group[i])
                for (int next : arr[now])
                    if (sccid[next] != i)
                        rec_num[sccid[next]]++;
        
        int count = 0;
        int answer_group = 0;
        for (int i = 0; i < scc_num; i++) {
            if (rec_num[i] == 0) {
                count++;
                answer_group = i;
            }
        }
        
        if (count != 1) {
            cout << "Confused" << '\n' << '\n';
            continue;
        }

        sort(group[answer_group].begin(), group[answer_group].end());
        for (int index : group[answer_group])
            cout << index << '\n';
        cout << '\n';
    }

    return 0;
}