#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<string.h>

using namespace std;

int V,E;
bool visit[100001];
vector<int> arr[10001];
vector<int> reverse_arr[10001];
vector<int> scc[10001];
stack<int> st;

bool compare(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

void scc_make(int index, int vertex) {
    visit[vertex] = true;
    scc[index].push_back(vertex);
    
    for(auto a : reverse_arr[vertex])
        if (visit[a] == false)
            scc_make(index,a);
}

void dfs(int vertex) {
    visit[vertex] = true;
    for (auto a : arr[vertex])
        if (visit[a] == false)
            dfs(a);
     
    st.push(vertex);
}

int main(void) {
    
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int ans = 0;
    
    cin >> V >> E;
    
    for (int i = 0; i < E; i++) {
        int a,b;
        cin >> a >> b;
        arr[a].push_back(b);
        reverse_arr[b].push_back(a);
    }
    
    for (int i = 1; i <= V; i++)
        if (visit[i] == false)
            dfs(i);
    
    for (int i = 1; i <= V; i++)
        visit[i] = false;
    
    while (!st.empty()) {
        int vertex = st.top();
        st.pop();
        
        if (visit[vertex] == false)
            scc_make(ans++,vertex);
    }
    
    for (int i = 0; i < ans; i++)
        sort(scc[i].begin(), scc[i].begin()+scc[i].size());
    sort( scc, scc+ans, compare);
    
    cout << ans << '\n';
    for (int i = 0; i < ans; i++) {
        for (auto a : scc[i])
            cout << a << ' ';
        cout << -1 << '\n';
    }
    
    
    return 0;
}
