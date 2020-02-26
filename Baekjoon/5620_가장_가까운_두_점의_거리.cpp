#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

#define INF 2100000000

using namespace std;

long long distance (pair<int, int> i, pair<int,int> j) {
    return pow(i.first-j.first,2) + pow(i.second-j.second,2);
}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;

    int end_line = 0;
    long long ans = 0;
    
    cin >> n;

    vector< pair<int, int> > v(n);
    map< pair<int,int> , bool> m;

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        
        v[i].first = a + 10000;
        v[i].second = b + 10000;
    }
    
    sort(v.begin(), v.end());

    ans = distance(v[0],v[1]);
    m[{v[0].second, v[0].first}] = true;
    m[{v[1].second, v[1].first}] = true;

    for (int i = 2; i < n; i++) {

        while ( end_line < i) {
            if ( pow(v[end_line].first-v[i].first,2) <= ans)
                break;

            m.erase({v[end_line].second, v[end_line].first});
            end_line++;            
        }

        int now_distance = sqrt(ans);

        auto up = m.upper_bound({v[i].second+now_distance, INF});
        auto down = m.lower_bound({v[i].second-now_distance, -INF});

        for (auto iter = down; iter != up; ++iter) {
            pair<int, int> key = (*iter).first;
            ans = min(ans, distance({key.second, key.first}, v[i]));
        }

        m[{v[i].second, v[i].first}] = true;
    }

    cout << ans;

    return 0;
}