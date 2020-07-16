#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

const double PI = 3.14159265;

struct info {
    int x,y;
    int px,py;
    info(int a, int b):x(a),y(b),px(1),py(0) {}

    bool operator<(const info& b)const {
        if ( py*b.px != px*b.py) return py*b.px < px*b.py;
        if (y != b.y) return y < b.y;
        return x < b.x;
    }
};

int N, L;
vector<info> arr;

int ccw(const info& p1, const info& p2, const info& p3) {
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}

double dist(const info& a, const info& b) {
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

double betw(const info& p1, const info& p2, const info& p3) {
    double v1 = dist(p1, p2);
    double v2 = dist(p2, p3);

    double x1 = (p1.x-p2.x);
    double x2 = (p3.x-p2.x);
    double y1 = (p1.y-p2.y);
    double y2 = (p3.y-p2.y);
    double se = acos( (x1*x2 + y1*y2) / (v1*v2) );
    
    return L*(PI - se);
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N >> L;
    
    for (int i = 0; i < N; i++) {
        int a,b;
        cin >> a >> b;
        arr.push_back(info(a,b));
    }

    sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size(); i++) {
        arr[i].px = arr[i].x - arr[0].x;
        arr[i].py = arr[i].y - arr[0].y;
    }
    sort(arr.begin()+1, arr.end());

    
    stack<int> s;
    s.push(0);
    s.push(1);

    for (int i = 2; i < arr.size(); i++) {
        while(s.size() >= 2) {
            int second = s.top();
            s.pop();
            int first = s.top();

            if (ccw(arr[first],arr[second],arr[i]) > 0) {
                s.push(second);
                break;
            }
        }
        s.push(i);
    }


    double answer = 0;
    vector<int> v(s.size());

    for (int i = v.size()-1; i >= 0; i--) {
        v[i] = s.top();
        s.pop();
    }

    for (int i = 0; i < v.size(); i++) {
        int now = v[i];
        int pre = v[(i+v.size()-1) % v.size()];
        int next = v[(i+1) % v.size()];
        answer += dist(arr[now] , arr[next]);
        answer += betw(arr[pre],arr[now],arr[next]);
        //cout << betw(arr[pre],arr[now],arr[next]) << '\n';
    }
    cout << round(answer) << '\n';

    return 0;
}