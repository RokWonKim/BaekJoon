#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

struct info {
    int x,y;
    int px,py;
    info(int a, int b):x(a),y(b),px(1),py(0) {}
};

vector<info> arr;

bool compare(const info& a, const info& b) {
    if (a.py*b.px != a.px*b.py) return a.py*b.px < a.px*b.py;
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

int ccw(const info& p1, const info& p2, const info& p3) {
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}

double dist(const info& a, const info& b) {
    return pow(a.x-b.x, 2) + pow(a.y-b.y, 2);
}

bool check(const info& a, const info& b, const info& c, const info& d) {
    info next = {b.x-a.x, b.y-a.y};
    info next_n = {d.x-c.x, d.y-c.y};
    return ccw(info(0,0), next, next_n) >= 0;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int C;
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
    double answer = 0;
    for (int i = 0; i < v.size(); i++) {
        while( p+1 < v.size() && check(arr[v[i]], arr[v[i+1]], arr[v[p]], arr[v[p+1]] ) ) {
            answer = max(answer, dist(arr[v[i]], arr[v[p]]) );
            ++p;
        }
        answer = max(answer, dist(arr[v[i]], arr[v[p]]) );
    }

    cout << fixed;
    cout.precision(10);

    cout << sqrt(answer) << '\n';

    return 0;
}