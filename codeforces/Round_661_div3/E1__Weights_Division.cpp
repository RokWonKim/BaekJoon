#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
//#include <bits/stdc++.h>

using namespace std;

int n;
long long s;
long long answer = 0;
// 그 간선이 몇번 사용되었는지
vector<int> wei;
vector<int> use_wei;
vector<vector< pair<int,int> >> v;

int dfs(int index, int parent) {
    if (v[index].size() == 1 && v[index][0].first == parent)
        return 1;
 
	int now_cnt = 0;
    for (pair<int,int> p : v[index]) {
        if (p.first == parent) continue;
 
		int now = dfs(p.first, index);
 
		use_wei[p.second] += now; 
		now_cnt += now;
    }
 
	return now_cnt;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        answer = 0;
		long long sum = 0;

        cin >> n >> s;
		v = vector<vector< pair<int,int> >> (n+1);
		wei = use_wei = vector<int> (n+1); 
		set<pair<long long,int>> values;

        for (int i = 0; i < n-1; i++) {
            int a,b,c;
            cin >> a >> b >> wei[i];
            v[a].push_back({b,i});
            v[b].push_back({a,i});
        }

        dfs(1,-1);
		for (int i = 0; i < n-1; i++) {
			values.insert({1LL*wei[i]*use_wei[i]-1LL*(wei[i]/2)*use_wei[i],i });
			sum += 1LL*wei[i]*use_wei[i];
		}

		while(sum > s) {
			int i = values.rbegin()->second;
			values.erase( prev(values.end()) );

            sum -= 1LL*wei[i]*use_wei[i]-1LL*(wei[i]/2)*use_wei[i];
            wei[i] /= 2;

			values.insert({wei[i]*1LL*use_wei[i]-1LL*(wei[i]/2)*use_wei[i], i});
			answer++;
		}
        
        cout << answer << '\n';
    }

    return 0;
}