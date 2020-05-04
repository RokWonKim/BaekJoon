#include<iostream>
#include<string.h>
#include<cmath>
#include<algorithm>

using namespace std;

const int INF = 987654321;

int N, S;
int arr[102];
double sum_arr[102];
int Quan[102][102];
// 몇번째구간, 몇번의 그룹(숫자의 수)을 썻는지
int dp[102][12];

int solve(int start, int group) {

	if (start > N) return 0;
	if (group > S) return INF;

	int &value = dp[start][group];
	if (value != -1)
		return value;
	
	value = INF;
	for (int i = start; i <= N; i++)
		value = min(value, Quan[start][i] + solve(i+1, group+1) );

	return value;
}


int main(void) {
	ios_base:: sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--) {
		memset(sum_arr, 0, sizeof(sum_arr));
		memset(dp, -1, sizeof(dp));
		cin >> N >> S;

		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		sort(arr+1,arr+N+1);
		for (int i = 1; i <= N; i++)
			sum_arr[i] = arr[i] + sum_arr[i-1];

		for (int i= 1; i <= N; i++) {
			Quan[i][i] = 0;
			for (int j = i+1; j <= N; j++) {
				Quan[i][j] = 0;
				int middle = round((sum_arr[j]-sum_arr[i-1])/(j-i+1));
				for (int x = i; x <= j; x++) {
					Quan[i][j] += pow(arr[x]-middle,2);
				}
			}
		}

		cout << solve(1,1) << '\n';
	}

	return 0;
}