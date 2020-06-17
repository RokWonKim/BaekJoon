#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#define MAX 100001

using namespace std;


int scc_size;
int num_ver;
int sccid[MAX];
int ver[MAX];
vector<int> arr[MAX];
vector<int> group[MAX];
stack<int> st;

int make_scc(int index) {
    int ret = ver[index] = num_ver++;
    st.push(index);
    for (int i = 0; i < arr[index].size(); i++) {
        int next = arr[index][i];

        if (ver[next] == -1)
            ret = min(ret, make_scc(next));
        else if (sccid[next] == -1)
            ret = min(ret, ver[next]);
    }

    if (ret == ver[index]) {
        while(true) {
            int val = st.top();
            st.pop();

            group[scc_size].push_back(val);
            sccid[val] = scc_size;
            if (val == index) break;
        }
        scc_size++;
    }
    
    return ret;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        scc_size = 0;
        num_ver = 0;
        memset(sccid, -1, sizeof(sccid));
        memset(ver, -1, sizeof(ver));

        for (int i = 0; i < MAX; i++) {
            arr[i].clear();
            group[i].clear();
        }

        int answer = 0;
        
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b);
        }
        
        for (int i = 1; i <= N; i++) 
            if (sccid[i] == -1)
                make_scc(i);
        
        vector<int> v(scc_size, 0);
        for (int i = 0; i < scc_size; i++) {
            for (int j = 0; j < group[i].size(); j++) {
                int part = group[i][j];
                for (int z = 0; z < arr[part].size(); z++) {
                    int val = arr[part][z];
                    if (sccid[val] != i)
                        v[sccid[val]]++;
                }
            }
        }

        for(int i = 0; i < scc_size; i++)
            if (v[i] == 0) answer++;

        cout << answer << '\n';
    }

    return 0;
}