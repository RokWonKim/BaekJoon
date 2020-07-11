#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>

using namespace std;

struct info {
    long long  x,y;
    long long px,py;

    info(long long a, long long b): x(a),y(b),px(1),py(0) {}
};

vector< pair<long long,long long> > moving;
vector<info> origin;

bool compare(const info& a, const info& b) {
    if (1LL*a.py*b.px != 1LL*a.px*b.py)
        return 1LL*a.py*b.px < 1LL*a.px*b.py;
    
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

long long ccw(const info& p1, const info& p2, const info& p3) {
    return (p2.x-p1.x)*(p3.y-p1.y) - (p2.y-p1.y)*(p3.x-p1.x);
}

long long dist(const info& a, const info& b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool check (const info& a, const info& b, const info& c, const info& d){
    info next = info(b.x-a.x, b.y-a.y);
    info next_next = info(d.x-c.x, d.y-c.y);
    return ccw(info(0,0), next, next_next) >= 0;
}

long long solve(int mul) {

    vector<info> arr;
    for (int i = 0; i < origin.size(); i++) 
        arr.push_back(info(origin[i].x + (1LL*moving[i].first*mul) ,origin[i].y + (1LL*moving[i].second*mul)));
    
    sort(arr.begin(), arr.end(), compare);
    for (int i = 1; i < arr.size(); i++) {
        arr[i].px = arr[i].x - arr[0].x;
        arr[i].py = arr[i].y - arr[0].y; 
    }
    sort(arr.begin()+1, arr.end(), compare);

    stack<int> s;
    s.push(0);
    s.push(1);

    for (int i = 2; i < arr.size(); i++) {
        while(s.size() >= 2) {
            int second = s.top();
            s.pop();
            int first = s.top();

            if (ccw(arr[first], arr[second], arr[i]) > 0) {
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
    long long part_answer = 0;
    for (int i = 0; i < v.size(); i++) {
        while (p+1 < v.size() && check(arr[v[i]],arr[v[i+1]],arr[v[p]],arr[v[p+1]] ) ) {
            part_answer = max(part_answer, dist(arr[v[i]], arr[v[p]]) );    
            p++;
        }
        part_answer = max(part_answer, dist(arr[v[i]], arr[v[p]]) );
    }

    return part_answer;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N, T;
    long long dist = 1e16;
    int day = 0;
    cin >> N >> T;

    for (int i = 0; i < N; i++) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        origin.push_back(info(a,b));
        moving.push_back({c,d});
    }

    int left = 0;
    int right = T;
    while (right - left >= 3) {
        int mid_1 = (left*2 + right)/3;
        int mid_2 = (left + right*2)/3;

        long long part_1 = solve(mid_1);
        long long part_2 = solve(mid_2);

        if (part_1 > part_2)
            left = mid_1;
        else
            right = mid_2;
    }

    for (int i = left; i <= right; i++) {
        long long part = solve(i);
        if (dist > part) {
            dist = part;
            day = i;
        }
    }
    cout << day << '\n' << dist << '\n';

    return 0;
}