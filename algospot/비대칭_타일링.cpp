#include<iostream>

using namespace std;

const int mod = 1000000007;
long long arr[102];
long long dp[102];

int main(void) {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= 100; i++) {
		arr[i] = (arr[i-1]+arr[i-2]) % mod;
		if (i%2 == 0)
			dp[i] = (arr[i] - arr[i/2] - arr[i/2-1] + 2*mod) % mod;
		else
			dp[i] = (arr[i] - arr[i/2] + mod) % mod; 
	}	
	
	while (T--) {

		int N;
		cin >> N;

		cout << dp[N] << '\n';
	}

	return 0;
}