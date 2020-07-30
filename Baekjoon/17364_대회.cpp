#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector< pair<int,int> > v;
multiset<int> s;

bool compare(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first > b.first;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    int answer = 0;
    int h_e = 0;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), compare);
    if (k == 1) {
        int e = -1;
        for (pair<int,int>& i : v) {
            if (i.first > e) {
                answer++;
                e = i.second;
            }
        }

        cout << answer <<'\n';
        return 0;
    }

    for(pair<int,int>& i : v) {
        if(i.first <= h_e) continue;
        if(s.empty()) {
            s.insert(i.second);
            continue;
        }

        auto back = s.lower_bound(i.first);
        if(back != s.begin()) {
            --back;
            s.erase(back);
            s.insert(i.second);
        }
        else {
            if(s.size() >= k-1) {
                answer++;
                h_e = i.second;
            }
            else s.insert(i.second);
        }
    }

   cout << answer << '\n';

   return 0;
}