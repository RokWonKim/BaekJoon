#include<iostream>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

const int INF = 1000000000;

int k;
vector<string> arr;
vector<string> cut_arr;
int dp[1 << 16][15];
int diff[15][15];
bool check[16];

int solve(int token, int last) {
    if (token == (1 << k)-1) return cut_arr[last].size();

    int &value = dp[token][last];
    if (value != -1) return value;

    value = INF;
    for (int i = 0; i < k; i++) {
        if ( (token & (1 << i)) == 0) {
            int newtoken = token | (1 << i);
            value = min(value, diff[last][i] + solve(newtoken, i) );
        }
    }
    return value;
}

string trace(int index, int token) {
    if (token == ((1 << k) - 1)) {
        return cut_arr[index];
    }

    int value = solve(token, index);
    for(int i = 0; i < k; i++) {
        if ( (token & (1 << i)) == 0) {
            int newtoken = token | (1 << i);
            if (value == ( solve(newtoken, i) + diff[index][i]) ) {
                return cut_arr[index].substr(0, diff[index][i]) + trace(i, newtoken);
            }
        }

    }
    return "";

}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(dp, -1, sizeof(dp));
        memset(check, false, sizeof(check));
        memset(diff, 0, sizeof(diff));
        arr.clear();
        cut_arr.clear();

        cin >> k;
        for(int i = 0; i < k; i++) {
            string s;
            cin >> s;
            arr.push_back(s);
        }

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i == j) continue;
                for (int x = 0; x < arr[i].size(); x++) {
                    if (arr[i][x] == arr[j][0]) {
                        for (int y = 0; y < arr[j].size(); y++) {
                            if (arr[i].size() <= x+y) break;
                            if (arr[i][x+y] == arr[j][y])  {
                                if (y == arr[j].size()-1) check[j] = true;
                                else continue;
                            }
                            break;
                        }
                    }
                }
            }
        }
        int num = 0;
        for (int i = 0; i < k; i++) {
            if (check[i] == false) cut_arr.push_back(arr[i]);
            else num++;
        }
        k -= num;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                int len = min(cut_arr[i].size(), cut_arr[j].size());
                diff[i][j] = cut_arr[i].size();
                while(len--) {
                    if ( cut_arr[i].substr(cut_arr[i].size()-len) == cut_arr[j].substr(0,len)) {
                        diff[i][j] = cut_arr[i].size() - len;
                        break;
                    }
                }
            }
        }

        int ans = INF;
        int ans_index = 0;
        for(int i = 0; i < k; i++) {
            int part = solve(1 << i, i);
            if (ans > part) {
                ans_index = i;
                ans = part;
            }
        }
        cout << trace(ans_index, 1 << ans_index) << '\n';
    }

    return 0;
}