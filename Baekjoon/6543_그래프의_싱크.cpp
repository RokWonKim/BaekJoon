#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<stack>
#include<set>

using namespace std;

bool visit[5001] = {false, };
vector<int> arr[5001];
vector<int> reverse_arr[5001];
vector<int> print_arr;
set<int> scc;
stack<int> st;


bool confirm() {
    
    for (int v : scc)
       for (int next : arr[v])
           if (scc.find(next) == scc.end())
               return false;
    
    return true;
}

void scc_make(int vertex) {
    visit[vertex] = true;
    scc.insert(vertex);
    
    for (int a : reverse_arr[vertex])
        if (!visit[a])
            scc_make(a);
}

void DFS(int vertex) {
    visit[vertex] = true;
    for(int a : arr[vertex])
        if (!visit[a])
            DFS(a);
    
    st.push(vertex);
}

int main(void) {
    
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        int n,m;
        
        cin >> n;
        if(n==0) break;
        cin >> m;
        
        for(int i = 0; i < m; i++) {
            int a,b;
            cin >> a >> b;
            arr[a].push_back(b);
            reverse_arr[b].push_back(a);
        }
        
        for (int i = 1; i <= n; i++)
            if (visit[i] == false)
                DFS(i);
        memset(visit, false, sizeof(visit));
        
        while (!st.empty()) {
            int vertex = st.top();
            st.pop();
            
            if (visit[vertex] == false) {
                scc_make(vertex);
                
                if ( confirm() )
                    for (int i : scc)
                        print_arr.push_back(i);
                scc.clear();
            }
        }
        
        sort(print_arr.begin(), print_arr.end());
        
        for (int i = 0; i < print_arr.size(); i++)
            cout << print_arr[i] << ' ';
        cout << '\n';
        
        for (int i = 1; i <= n; i++) {
            arr[i].clear();
            reverse_arr[i].clear();
        }
        print_arr.clear();
        memset(visit, false, sizeof(visit));
    }
    
    
    return 0;
}
