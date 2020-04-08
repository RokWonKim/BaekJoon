#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(void) {
    
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--) {
        
        int n, m;
        bool flag = false;
        cin >> n >> m;
        
        // 값 저장
        vector<int> arr(m+1);
        
        // Yes일 경우 출력하는 곳
        vector<int> print_ans(m+1 ,-1);
        
        // 각 호수를 언제 마셨는지(마셧을때의 인덱스)
        vector<int> where_appear(n+1, -1);
        
        // 0이 나온 곳의 인덱스를 저장함
        set<int> s;
        
        for (int i = 1; i <= m; i++)
            cin >> arr[i];
        
        for (int i = 1; i <= m; i++) {
            
            if ( arr[i] == 0) {
                s.insert(i);
            }
            else {
                int value = arr[i];
                
                // value를 언제 마셧는지를 봄. 마신 인덱스보다 큰 0의 인덱스가 있는지 확인함
                auto it = s.upper_bound(where_appear[value]);
                
                if (it == s.end()) {
                    flag = true;
                    break;
                }
                print_ans[*it] = value;
                where_appear[value] = i;
                s.erase(it);
            }
        }
        
        if (flag)
            cout << "NO";
        else {
            cout << "YES" << '\n';
            
            for (int i = 1; i <= m; i++)
                if (arr[i] == 0) {
                    if (print_ans[i] == -1)
                        cout << 0 << ' ';
                    else
                        cout << print_ans[i] << ' ';
                }
                    
        }
        
        cout << '\n';
    }
    
    
    return 0;
}
