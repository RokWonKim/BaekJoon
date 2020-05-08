#include<iostream>
#include<string.h>

using namespace std;

const int m = 10000000;

// 몇개로 이루어졌는지, 가장 윗줄에 몇개인지
int dp[102][102];

int solve(int all_num, int first_num) {

	if (all_num == first_num) return 1;

	int &value = dp[all_num][first_num];

	if (value != -1) return value;

	value = 0;
	for (int next_num = 1; next_num <= all_num-first_num; next_num++) {
		int possible = first_num + next_num -1;
		possible *= solve(all_num-first_num, next_num);

		possible %= m;
		value += possible;
		value %= m;
	}

	return value;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));
	int T;
	cin >> T;
	while(T--) {
		
		int N;
		cin >> N;
		int ans = 0;
		
		for (int i = 1; i <= N; i++)
			ans = (ans + solve(N, i)) % m;

		cout << ans << '\n';
		
	}
	return 0;
}