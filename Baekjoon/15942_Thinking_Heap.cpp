#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int answer[200001];
bool check[200001];
int N;
int child_num;

void dfs(int x) {
    if (x > N) return;

    child_num++;
    dfs(x*2);
    dfs(x*2+1);
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int K,P;
    int n,k,p;

    cin >> N;
    cin >> K >> P;

    n=N;
    k=K;
    p=P;
    
    int n_num = 0;
    while(n != 0) {
        n/=2;
        n_num++;
    }
    n = N;

    int p_num = 0;
    while(p != 0) {
        p/=2;
        p_num++;
    }
    p = P;
    dfs(P*2);
    dfs(P*2+1);
    if ( K-1 < p_num-1 || child_num > N-K ) {
        cout << -1 << '\n';
        return 0;
    }




    vector<int> v;
    answer[P] = K;
    check[K] = true;
    p = P;

    while(p/2 != 0) {
        int d = p/2;
        v.push_back(d);
        p/=2;
    }

    int start = 1;
    for (int i = v.size()-1; i >= 0; i--) {
        answer[v[i]] = start;
        check[start] = true;
        start++;
    }


    start = K+1;
    queue<int> q;
    q.push(P*2);
    q.push(P*2+1);

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if (now > N) break;

        answer[now] = start;
        check[start] = true;
        start++;
        q.push(now*2);
        q.push(now*2+1);
    }

    
    start = 1;
    for (int i = 1; i <= N; i++) {
        if (answer[i] == 0) {
            while(check[start]) start++;
            answer[i] = start;
            check[start] = true;
            start++;
        }
    }
    
   for (int i = 1; i<= N; i++) cout << answer[i] << '\n';

    return 0;
}