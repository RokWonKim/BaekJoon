#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>


using namespace std;

struct info{
    int x,y;
    int px,py;

    info(int a, int b):x(a),y(b),px(1),py(0) {}
};

vector<info> arr;

bool compare(const info& a, const info& b) {
    if ( 1LL*a.py*b.px != 1LL*a.px*b.py) return 1LL*a.py*b.px < 1LL*a.px*b.py;
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

long long ccw(const info& p1, const info& p2, const info& p3) {
    return 1LL*(p2.x-p1.x)*(p3.y-p1.y)-1LL*(p2.y-p1.y)*(p3.x-p1.x);
}

long long dist(const info& a, const info& b) {
    return 1LL*(a.x-b.x)*(a.x-b.x) + 1LL*(a.y-b.y)*(a.y-b.y);
}

bool check(const info& a, const info& b, const info& c, const info& d) {
    info next = info(b.x-a.x, b.y-a.y);
    info next_next = info(d.x-c.x, d.y-c.y);
    return ccw(info(0,0), next, next_next) >= 0;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        arr.clear();

        int C;
        long long max_dist = 0.0;
        pair<int,int> start = {0,0};
        pair<int,int> end = {0,0};

        cin >> C;
        for (int i = 0; i < C; i++) {
            int a,b;
            cin >> a >> b;
            arr.push_back(info(a,b));
        }

        sort(arr.begin(), arr.end(), compare);
        for (int i = 1; i < arr.size(); i++) {
            arr[i].px = arr[i].x - arr[0].x;
            arr[i].py = arr[i].y - arr[0].y;
        }
        sort(arr.begin()+1, arr.end(), compare);

        stack<int> s;
        s.push(0);
        s.push(1);

        for (int i =2; i < arr.size(); i++) {
            while(s.size() >= 2) {
                int second = s.top();
                s.pop();
                int first = s.top();
                if (ccw(arr[first], arr[second], arr[i] ) > 0) {
                    s.push(second);
                    break;
                }
            }
            s.push(i);
        }

        vector<int> v(s.size());
        for (int i = v.size()-1; i >= 0; i--) {
            v[i] = s.top();
            s.pop();
        }

        int p = 0;
        for (int i = 0; i < v.size(); i++) {
            while(p+1 < v.size() && check(arr[v[i]],arr[v[i+1]],arr[v[p]],arr[v[p+1]]) ) {
                long long part = dist(arr[v[i]], arr[v[p]] );
                if (max_dist < part) {
                    max_dist = part;
                    start = {arr[v[i]].x, arr[v[i]].y};
                    end = {arr[v[p]].x, arr[v[p]].y };
                }
                p++;
            }
            long long part = dist(arr[v[i]], arr[v[p]] );
            if (max_dist < part) {
                max_dist = part;
                start = {arr[v[i]].x, arr[v[i]].y};
                end = {arr[v[p]].x, arr[v[p]].y };
            }
        }
        
        cout << start.first << ' ' << start.second << ' ' << end.first << ' ' << end.second << '\n';
    }

    return 0;
}