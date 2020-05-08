#include<cstdio>
#include<vector>
#include<string.h>

using namespace std;

vector<double> arr[52];
int n,d,p;

// 각 마을, 몇일이 지났는지 => 확률
double dp[52][102];

//현재 마을, 몇일 지났는지
double solve(int town, int day) {
	if (day == 1) {
		if ( dp[town][day] == -1) return 0;
		else return dp[town][day];
	}

	double &value = dp[town][day];
	if (value != -1) return value;

	value = 0;
	for (auto i : arr[town]) {
		value += ( solve(i, day-1) * (1/(double)arr[(int)i].size()) );
	}

	return value;
}


int main(void) {

	int T;
	scanf("%d", &T);
	
	while(T--) {

		int calcum_n;
		scanf("%d %d %d", &n, &d, &p);
		
		for(int i = 0; i < n; i++) {
			arr[i].clear();
			for(int j = 0; j <= d; j++)
				dp[i][j] = -1;
		}
		

		for(int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				
				int value;
				scanf("%d", &value);
				if (value == 1)
					arr[i].push_back(j);
			}
		}

		for(int a : arr[p])
			dp[a][1] = 1/(double)arr[p].size();

		scanf("%d", &calcum_n);
		for(int i = 0; i < calcum_n; i++) {
			int value;
			scanf("%d", &value);

			printf("%.8lf ", solve(value, d));
		}
		printf("\n");
	}

	return 0;
}