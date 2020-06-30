#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct info{
    int v;
    int l;
};

info seg[20000*4];
vector< pair<int,int> > arr;
vector<int> v;
bool visit[20001];
int cnt;

void update(int start, int end, int a, int b, int val, int loc){
    if (seg[loc].l != 0) {
        seg[loc].v = seg[loc].l;
        if(start != end) {
            seg[loc*2].l = seg[loc].l;
            seg[loc*2+1].l = seg[loc].l;
        }
        seg[loc].l = 0;
    }

    if (end < a || start > b) return;
    else if (a <= start && b >= end) {
        seg[loc].v = val;
        if (start != end) {
            seg[loc*2].l = val;
            seg[loc*2+1].l = val;
        }
        return;
    }
    int mid = (start+end)/2;
    update(start,mid,a,b,val,loc*2);
    update(mid+1,end,a,b,val,loc*2+1);
    seg[loc].v = seg[loc*2].v + seg[loc*2+1].v;
}

void confirm(int start, int end, int loc) {

    if (seg[loc].l != 0) {
        seg[loc].v = seg[loc].l;
        if(start != end) {
            seg[loc*2].l = seg[loc].l;
            seg[loc*2+1].l = seg[loc].l;
        }
        seg[loc].l = 0;
    }

    if (start == end) {
        if (seg[loc].v != 0 && !visit[seg[loc].v]) {
            cnt++;
            visit[seg[loc].v] = true;
        }
        return;
    }
    int mid = (start+end)/2;
    confirm(start,mid,loc*2);
    confirm(mid+1,end,loc*2+1);

}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a,b;
        cin >> a >> b;

        arr.push_back({a,b});
        v.push_back(a);
        v.push_back(b);
    }

    sort(v.begin(), v.end());
    v.erase( unique(v.begin(),v.end()), v.end());
    v.push_back(100000001);

    for (int i = 0; i < N; i++) {
        int start = arr[i].first;
        int end = arr[i].second;

        int start_index = lower_bound(v.begin(), v.end(), start) - v.begin();
        int end_index = lower_bound(v.begin(), v.end(), end) - v.begin();    
        update(0, 20000, start_index, end_index,i+1, 1);
    }
    confirm(0,20000,1);

    cout << cnt << '\n';

    return 0;
}
