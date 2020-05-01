#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<string.h>

using namespace std;

string str;
string compare;
int cache[102][102];

int solve(int s, int com) {

    int &value = cache[s][com];

    if (compare.size() == com) {
        if (str.size() == s) return 1;   
        else {
            if (str[s] == '*') return value = solve(s+1, com);
            else return 0;
        }
    }
    else if (str.size() == s) return 0;
        
    // * 때문에 DP가 가능
    if (value != -1)
        return value;

    value = 0;
    // 서로 맞을 때 앞으로 넘김
    if ( str[s] == compare[com] || str[s] == '?' )
        value = solve(s+1, com+1);
    // *일때
    else if (str[s] == '*')
        value = max(solve(s, com+1), max(solve(s+1,com+1), solve(s+1,com) ));
    // 서로 다른 문자일때(와일드카드 아님)
    else value = 0;

    return value;
}

int main(void) {
    ios_base:: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        vector<string> ans;

        cin >> str;
        cin >> N;
        
        for (int i = 0; i < N; i++) {
            memset(cache, -1, sizeof(cache));
            cin >> compare;
            int value = solve(0,0);
            if (value == 1) ans.push_back(compare);
        }

        sort(ans.begin(), ans.end());

        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << '\n';

    }

    return 0;
}