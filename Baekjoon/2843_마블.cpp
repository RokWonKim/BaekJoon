#include<iostream>
#include<vector>

using namespace std;

int union_find[300002];
pair<int,int> query[300002];
int arr[300002];
bool can_not_use[300002];

int find(int x) {
    if (union_find[x] == x)
        return x;
    
    return union_find[x] = find(union_find[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    
    if (x != y)
        union_find[x] = y;
    else {
        // 싸이클이 있다
        union_find[x] = 0;
        union_find[y] = 0;
    }
    
}

int main(void) {
    
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int N,M;
    cin >> N;
    
    vector<int> ans;
    
    for (int i = 1 ; i <= N; i++) {
        cin >> arr[i];
        union_find[i] = i;
    }
    
    
    cin >> M;
    //쿼리르 받으면서 끊어놓는 곳을 can_not_use에 true로 만들어놓음
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        
        query[i].first = a;
        query[i].second = b;
        
        if (a == 2) can_not_use[b] = true;
    }
    
    for (int i = 1; i <= N; i++)
        if ( can_not_use[i] == false && arr[i] != 0)
            merge(i, arr[i]);
    
    //쿼리를 뒤에서 부터 확인함
    for (int i = M-1; i >= 0; i--) {
        int value = query[i].second;
        
        if (query[i].first == 1) {
            int part_ans = find(value);
            
            if (part_ans == 0)
                ans.push_back(0);
            else
                ans.push_back(part_ans);
        }
        else {
            if (arr[value] != 0)
                merge(value, arr[value]);
        }
            
    }
    
    for (int i = ans.size() - 1; i >= 0; i--) {
        if (ans[i] == 0)
            cout << "CIKLUS" << '\n';
        else
            cout << ans[i] << '\n';
    }
    
    return 0;
}
