#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

double wei[10000];
vector< pair<int,double> > arr[10000];

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(wei, 0, sizeof(wei));
		int N, M;
		scanf("%d %d", &N, &M);

		for(int i = 0; i < N; i++) arr[i].clear();
		for (int i = 0; i < M; i++) {
			int a, b;
			double c;
			scanf("%d %d %lf", &a, &b, &c);

			arr[a].push_back({b,c});
			arr[b].push_back({a,c});
		}

		priority_queue< pair<double,int> > q;
		q.push({-1,0});

		while(!q.empty()) {
			double cur = -q.top().first;
			int now = q.top().second;
			q.pop();

			if( wei[now] != 0) continue;
			wei[now] = cur;

			for(pair<int,double> next : arr[now]) {
				double next_cur = cur * next.second;
				int next_ver = next.first;
				q.push({-next_cur, next_ver});
			}
		}

		printf("%.8lf\n", wei[N-1]);
	}

	return 0;
}