#include<iostream>
#include<functional>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int cost[101];
int weight[2001];

int main(void)
{
	int test_case;
	int T;

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case) {
        priority_queue<int,vector<int>,greater<int> > pq;
        queue<int> q;
        map<int, int> ma;
        
        int n = 0;
        int m = 0;
        int ans = 0;
        
        cin >> n >> m;
        
        for (int i = 1; i <= n; i++) {
            cin >> cost[i];
            pq.push(i);
        }
        
        for (int i = 1; i <= m; i++)
            cin >> weight[i];
        
        int car_num = 0;
        for(int i = 0; i < 2*m; i++) {
            cin >> car_num;
            
            if (car_num > 0) {
                q.push(car_num);
                
                int in_car = q.front();
                
                if ( !pq.empty() ) {
                    int place_num = pq.top();
                    pq.pop();
                    q.pop();

                    ma[in_car] = place_num;
                    ans += weight[in_car] * cost[place_num];
                }
            }
            else {
                pq.push(ma[-car_num]);
                
                if ( !q.empty() ) {
                    int place_num = pq.top();
                    pq.pop();
                    int in_car = q.front();
                    q.pop();

                    ma[in_car] = place_num;
                    ans += weight[in_car] * cost[place_num];
                }
            }            
        }
        cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}