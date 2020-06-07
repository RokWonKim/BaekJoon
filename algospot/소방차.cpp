#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define f(a, i) for(i = 0; i < a; i++)

using namespace std;

vector<pair<int,int> > arr[1001];
int wei[1001];
int station[1001];
int fire[1001];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--) {
		memset(wei, -1, sizeof(wei));

		priority_queue<pair<int,int>> q;
		int v,e,n,m;
		int i;
		int answer = 0;
		cin >> v >> e >> n >> m;
		f(v+1,i) arr[i].clear();
		f(e,i) {
			int a,b,c;
			cin >> a >> b >> c;
			arr[a].push_back({b,c});
			arr[b].push_back({a,c});
		}
		f(n,i) cin >> fire[i];
		f(m,i) {
			cin >> station[i];
			q.push({0, station[i]});
		}

		while(!q.empty()) {
			int cur_wei = -q.top().first;
			int now_ver = q.top().second;
			q.pop();

			if( wei[now_ver] != -1) continue;
			wei[now_ver] = cur_wei;

			for(pair<int,int>& next : arr[now_ver]) {
				int next_wei = cur_wei + next.second;
				int next_ver = next.first;
				
				q.push({-next_wei, next_ver});
			}
		}

		f(n,i) answer += wei[fire[i]];
		cout << answer << '\n';
	}

	return 0;
}