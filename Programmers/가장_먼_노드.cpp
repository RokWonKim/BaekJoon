#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> arr[20001];
bool visit[20001];
int distan[20001];
int far;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for (int i = 0; i < edge.size(); i++) {
        int x = edge[i][0];
        int y = edge[i][1];
        
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    
    queue<pair<int,int>> q;
    q.push({1,0});
    while(!q.empty()) {
        int now = q.front().first;
        int dis = q.front().second;
        q.pop();
        
        if (visit[now]) continue;
        visit[now] = true;
        distan[now] = dis;
        far = max(far,dis);
        
        for(int next : arr[now])
            if (!visit[next])
                q.push({next, dis+1});
    }
    
    for (int i = 1; i <= n; i++) if(far == distan[i]) answer++;
    
    return answer;
}