#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

const long long INF = 100000000000;

int N,K;
int arr[502];
int dp[502];
long long len[502];
vector<int> ans;

int solve(int index) {

    int &value = dp[index];
    if (value != -1) return value;

    value = 1;
    for (int i = index+1; i <= N; i++)
        if (arr[index] < arr[i])
            value = max(value, solve(i)+1);

    return value;
}

long long count(int index) {

    if (solve(index) == 1) return 1;

    long long &value = len[index];
    if (value != -1) return value;

    value = 0;
    for (int i = index+1; i <= N; i++) {
        if (arr[index] < arr[i] && solve(index) == solve(i)+1) {
            value = min(INF, value + count(i));
        }
    }
    return value;
}

void trace(int index, long long k) {
    
    if (index != 0) ans.push_back(arr[index]);

    vector <pair<int,int> > now;
    for (int i = index+1; i <= N; i++)
        if (arr[index] < arr[i] && solve(index) == solve(i)+1)
            now.push_back({arr[i], i});

    sort(now.begin(), now.end());

    for (int i = 0; i < now.size(); i++) {
        int loc = now[i].second;
        long long cot = count(loc);

        if (cot <= k) k -= cot;
        else {
            trace(loc, k);
            break;
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        ans.clear();
        memset(dp, -1, sizeof(dp));
        memset(len, -1, sizeof(len));
        cin >> N >> K;

        for(int i = 1; i <= N; i++)
            cin >> arr[i];

        arr[0] = -1;
        cout << solve(0)-1 << '\n';
        count(0);
        trace(0, K-1);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}