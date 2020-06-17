#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<cstring>

using namespace std;

int N;
int num_ver;
int scc_size;
int discover[401];
int sccid[401];
vector<pair<int,int>> arr;
vector<int> graph[401];
stack<int> st;

bool disjoint(const pair<int,int>& a, const pair<int,int>& b) {
    return a.second <= b.first || b.second <= a.first;
}

void make2sat() {
    int size = arr.size();

    //한 팀 안에서 두 개의 회의사간 중 하나만 true면 됌
    for (int i = 0; i < size; i += 2) {
        int j = i+1;
        graph[i*2+1].push_back(j*2);
        graph[j*2+1].push_back(i*2);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {

            // a가 true 면 b는 false여야 하므로 !b를 저장
            if (!disjoint(arr[i],arr[j])) {
                graph[i*2].push_back(j*2+1);
                graph[j*2].push_back(i*2+1);
            }
        }
    }
}

int make_scc(int now) {
    int ret = discover[now] = num_ver++;
    st.push(now);
    for (int i = 0; i < graph[now].size(); i++) {
        int next = graph[now][i];
        if (discover[next] == -1)
            ret = min(ret, make_scc(next));
        else if (sccid[next] == -1)
            ret = min(ret, discover[next]);
    }

    if (ret == discover[now]) {
        while(true) {
            int val = st.top();
            st.pop();

            sccid[val] = scc_size;
            if (now == val) break;
        }
        scc_size++;
    }

    return ret;
}

vector<int> solve() {
    
    for (int i = 0; i < N*4; i++)
        if (discover[i] == -1)
            make_scc(i);
    
    // 같은 회의의 not 과 그냥이 같은 경우 모순이 일어남
    for (int i = 0; i < 4*N; i += 2)
        if (sccid[i] == sccid[i+1]) 
            return vector<int>();

    vector<int> value(N*2, -1);
    vector<pair<int,int>>order;
    // 타잔의 scc는 위상정렬의 역순으로 scc번호를 가짐(반환 하면서 scc인지 정하기 때문)
    for (int i = 0; i < 4*N; i++)
        order.push_back({-sccid[i], i});

    sort(order.begin(), order.end());

    for (int i = 0; i < 4*N; i++) {
        int vertex = order[i].second;
        int vari = vertex/2;
        int isTrue = (vertex % 2 == 0);

        if (value[vari] != -1) continue;

        // 먼저 나온게 아니라 그 다음 나오는 걸로 함
        // true가 먼저 나오고 뒤에 false가 나오면 true->false이므로 모순이 됨
        // false -> true여야함
        value[vari] = !isTrue;
    }

    return value;


}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        num_ver = 0;
        scc_size = 0;
        memset(sccid, -1, sizeof(sccid));
        memset(discover, -1, sizeof(discover));
        for (int i = 0; i < 401; i++) graph[i].clear();

        cin >> N;
        arr.clear();
        arr.resize(N*2);

        for (int i = 0; i < N; i++) {
            cin >> arr[i*2].first >> arr[i*2].second;
            cin >> arr[i*2+1].first >> arr[i*2+1].second;
        }

        make2sat();

        vector<int> ans = solve();
        if (ans.empty()) cout << "IMPOSSIBLE" << '\n';
        else {
            cout << "POSSIBLE" << '\n';
            for (int i = 0; i < ans.size(); i += 2) {
                // 둘다 true인 경우가 있기에
                if (ans[i] == 1 || ans[i+1] == 0)
                    cout << arr[i].first << ' ' << arr[i].second << '\n';
                else
                    cout << arr[i+1].first << ' ' << arr[i+1].second << '\n';
            }
        }

    }

    return 0;
}