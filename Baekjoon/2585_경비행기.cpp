#include<iostream>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

vector< pair<int, int> > v;
int n, k;

bool BFS(int mid) {
    queue< pair<int, int> > q;
    bool visit[1003] = {false, };

    visit[0] = true;
    q.push({0, 0});

    while(!q.empty()) {
        int start = q.front().first;
        int num = q.front().second;
        q.pop();

        if (start == n+1) {
            if (num > k + 1) return false;
            else return true;
        }

        for (int i = 1; i < n+2; i++) {
            if (visit[i] != true) {
                int value = int(ceil(sqrt(pow(v[start].first-v[i].first,2) + pow(v[start].second-v[i].second,2))));
                if (value <= mid) {
                    visit[i] = true;
                    q.push({i, num+1});
                }
            }
        }
    }

    return false;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int left = 1;
    int right = int(ceil(sqrt(pow(10000,2)*2)));
    int mid = 0;
    int ans = 2100000000;
    bool okay = false;

    cin >> n >> k;

    v.resize(n+2);
    
    v[0] = {0,0};
    for (int i = 1; i <= n; i++)
        cin >> v[i].first >> v[i].second;
    v[n+1] = {10000,10000};


    while (left <= right) {
        mid = (left+right) /2;

        okay = BFS(mid);
        
        if (okay == true) {
            right = mid-1;
            ans = min(ans, mid);
        }
        else left = mid+1;
    }

    cout << ceil(double(ans)/10);

    return 0;
}