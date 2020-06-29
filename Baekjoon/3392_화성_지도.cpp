#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info{
    int x;
    int top_y;
    int bottom_y;
    int inc;

    bool operator<(const info& a) const {
        return x < a.x;
    }
};

int seg[30000*4];
int cnt[30000*4];
vector<info> arr;

void update(int start, int end, int a, int b, int val, int loc) {

    if (end < a || start > b) return;
    else if (a <= start && b >= end)
        cnt[loc] += val;
    else {
        int mid = (start+end)/2;
        update(start,mid,a,b,val,loc*2);
        update(mid+1,end,a,b,val,loc*2+1);
    }

    seg[loc] = 0;
    if (cnt[loc] > 0)
        seg[loc] = end-start+1;
    else if (start != end)
        seg[loc] = seg[loc*2] + seg[loc*2+1];
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    int answer = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        arr.push_back({x1,y2,y1,1});
        arr.push_back({x2,y2,y1,-1});
    }
    sort(arr.begin(), arr.end());

    int start_ver = arr[0].x;

    for (int i = 0; i < arr.size(); i++) {
        answer += (arr[i].x - start_ver) * seg[1];
        update(0, 30000, arr[i].bottom_y, arr[i].top_y-1, arr[i].inc, 1);
        start_ver = arr[i].x;
    }

    cout << answer <<'\n';

    return 0;
}