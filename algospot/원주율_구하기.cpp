#include<iostream>
#include<cmath>
#include<string>
#include<string.h>

using namespace std;

const int INF = 987654321;

int dp[10002];
int diff[10002];
int arr[10002];

int confirm(int num, int start) {
	bool zero = true;
	bool same = true;
	int value;
	for (int i = start; i > start-num; i--) {
		if (i == start) value = diff[i];
		if (diff[i] != 0) zero = false;
		if (value != diff[i]) same = false;
	}
	if (zero) return 1;
	else if (same)  {
		if ( value == 1 || value == -1) return 2;
		else return 5;
	}

	bool abs_same = false;
	if (num == 2){
		if (diff[start] == -diff[start-1]) 
			abs_same = true;
	}
	else if (num == 3) {
		if ( diff[start] == diff[start-2] && diff[start] == -diff[start-1] )
			abs_same = true;
	}
	else if (num == 4) {
		if ( diff[start] == diff[start-2] && 
			diff[start-1] == diff[start-3] && 
			diff[start] == -diff[start-1])
			abs_same = true;
	}
		
	if (abs_same) return 4;

	
	
	return 10;
}

int main(void) {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(dp));
		string str;
		cin >> str;
		for (int i = 0; i< str.size(); i++) {
			arr[i] = str[i]-'0';
			dp[i] = INF;
			if (i > 0)
				diff[i] = arr[i] - arr[i-1];
		}
		
		
		// -2 ~ -4
		for (int i = 2; i < str.size(); i++) {
			if (i == 2) {
				dp[i] = confirm(2,i);
				continue;
			}
			else if (i == 3) {
				dp[i] = confirm(3,i);
				continue;
			}
			else if (i == 4) {
				dp[i] = confirm(4,i);
				continue;
			}
			for (int j = 3; j <= 5; j++) {
				dp[i] = min(dp[i], confirm(j-1,i) + dp[i-j] );
			}

			//dp[i-3] arr[i-2 ~ i] 
			//dp[i-4] arr[i-3  ~ i]
			//dp[i-5] arr[i-4 ~ i] 3개중 최솟값을 저장

		}
		cout << dp[str.size()-1] <<'\n';

	}
	return 0;
}