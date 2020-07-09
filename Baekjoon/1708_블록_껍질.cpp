#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

struct info{
    int x, y;
    int px, py;

    info(int a, int b) : x(a),y(b),px(1),py(0) {}
};

vector<info> arr;

bool compare(const info& a, const info& b) {
    // 벡터의 외적과 같음 (y2-y1)*(x3-x1) < (x2-x1)*(y3-y1)
    if ( 1LL*a.px*b.py != 1LL*a.py*b.px )
        return 1LL*a.py*b.px < 1LL*a.px*b.py;

    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

long long ccw(const info& p1, const info& p2, const info& p3) {
    return 1LL*(p2.x-p1.x)*(p3.y-p1.y) - 1LL*(p2.y-p1.y)*(p3.x-p1.x);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
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

    // 점의 인덱스를 넣음
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

    cout << s.size() << '\n';

    return 0;
}
