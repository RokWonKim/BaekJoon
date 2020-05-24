#include<iostream>
#include<vector>
#include<set>
#include<cstring>

using namespace std;

const int INF = 10000000;

int n,k,m,l;
// 어느학기에서, 몇가지의 수업을 들었을때 = 최소 들은 학기 수
int dp[12][1 << 13];

// 각 과목의 선수과목 비트마스크로 저장
int pre_carry[13];
// 각 학기에 열리는 과목들 비트마스크로 저장
vector<int> seme[10];

void backtracking(vector<int>& back_arr,vector<int>& make_value ,int num,int now_index, int value) {
    if (num == l) {
        make_value.push_back(value);
        return;
    }

    for (int i = now_index; i < back_arr.size(); i++)
        backtracking(back_arr, make_value, num+1, i+1, value | (1 << back_arr[i]) );

}

int solve(int now, int listen, int num) {


    if (num >= k) return 0;
    if (now == m) return INF;

    int &value = dp[now][listen];
    if (value != -1) return value;

    value = solve(now+1, listen, num);

    int incre = 0;
    int incre_k = 0;
    vector<int> back_arr;
    
    for (int i = 0; i < seme[now].size(); i++) {
        int open_seme = seme[now][i];

        // 그냥 들어도 된다는 뜻
        if (pre_carry[open_seme] == 0) {
            if( (listen & (1 << open_seme)) == 0) back_arr.push_back(open_seme);
        }
        else {
            // 선행과목을 다 들음
            if ( (listen & pre_carry[open_seme]) == pre_carry[open_seme]) {
                if( (listen & (1 << open_seme)) == 0) back_arr.push_back(open_seme);
            }
        }
    }
    if ( back_arr.size() <= l) {
        int sum = 0;

        for (int i = 0; i < back_arr.size(); i++)
            sum += (1 << back_arr[i]);

        value = min(value, solve(now+1, listen+sum, num+back_arr.size())+1 );
    }   
    else {
        vector<int> make_value;
        backtracking(back_arr, make_value, 0,0,0);

        for (int i = 0; i < make_value.size(); i++)
            value = min(value, solve(now+1, listen+make_value[i], num+l)+1 );
    }

    return value;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(dp, -1, sizeof(dp));
        memset(pre_carry, 0, sizeof(pre_carry));
        for (int i = 0; i < 10; i++) seme[i].clear();

        cin >> n >> k >> m >> l;

        for (int i = 0; i < n; i++) {
            int value;
            int sum = 0;
            cin >> value;
            set<int> s;
            for (int j = 0; j < value; j++) {
                int index;
                cin >> index;
                if (s.find(index) == s.end()) {
                    sum += (1 << index);
                    s.insert(index);
                }
            }
            pre_carry[i] = sum;
        }

        for (int i = 0; i < m; i++) {
            int value;
            int sum = 0;
            cin >> value;
            set<int> s;
            for (int j = 0; j < value; j++) {
                int index;
                cin >> index;
                if (s.find(index) == s.end()) {
                    seme[i].push_back(index);
                    s.insert(index);
                }
                
            }
        }

        int ans = solve(0, 0, 0);
        if (ans >= INF) cout << "IMPOSSIBLE" << '\n';
        else cout << ans << '\n';

    }

    return 0;
}