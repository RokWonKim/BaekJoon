#include <iostream>
#include <vector>
#include <cstring>
#define MAX 3002

using namespace std;

const int INF = 987654321;

int N;
int arr[MAX][MAX];
int sum[MAX][MAX];
int inner[MAX][MAX];
int outer[MAX][MAX];
int dp[MAX];

vector<int> v;

int solve(int start) {
    if (start > N) return 0;

    int &value = dp[start];
    if (value != -1) return value;

    value = INF;
    for (int i = start; i <= N; i++)
        value = min(value, inner[start][i] + outer[start][i] + solve(i+1));

    return value;
}

void trace(int start, int ans) {
    if (start > N) return;

    for (int i = start; i <= N; i++) {
        if (inner[start][i] + outer[start][i] + solve(i+1) == ans) {
            //cout << inner[start][i] << ' ' << outer[start][i] <<'\n';
            trace(i+1, ans - inner[start][i]-outer[start][i]);
            v.push_back(i-start+1);
            return;
        }
    }
}

int main(void)  {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 1; i <= N; i++) {
        while(1) {
            int num;
            cin >> num;
            if (num == 0)break;
            arr[i][num] = 1;
        }
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            sum[i][j] = sum[i-1][j] + sum[i][j-1] +arr[i][j] - sum[i-1][j-1];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++)
            arr[j][i] += arr[j-1][i];

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            inner[i][j] = inner[i][j-1] + ( (j-i) - (arr[j][j] - arr[i-1][j] ));
            outer[i][j] = sum[N][j]-sum[N][i-1] - (sum[j][j]-sum[j][i-1]) ;
        }
    }


    int answer = solve(1);
    trace(1, answer);
    cout << answer << '\n';
    cout << v.size() << ' ';

    for (int i = v.size()-1; i >= 0; i--) cout << v[i] << ' ';
    cout << '\n';

    return 0;
}