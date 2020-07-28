#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 100001

using namespace std;

vector<int> seg[MAX*4];

void update(int start, int end, int v, int index, int loc) {
    if (start > index || end < index) return;

    seg[loc].push_back(v);
    if (start != end) {
        int mid = (start + end)/2;
        update(start,mid,v,index,loc*2);
        update(mid+1, end, v, index, loc*2+1);
    }
}

int q(int start, int end, int a, int b, int v, int loc) {
    if (start > b || end < a) return 0;
    else if (a <= start && end <= b) {
        int index = upper_bound(seg[loc].begin(), seg[loc].end(), v) - seg[loc].begin();
        if (seg[loc][index] > v) return seg[loc].size() - index;
        else return 0;
    }

    int mid = (start + end) / 2;
    return q(start, mid, a, b, v, loc*2) + q(mid+1, end, a, b, v, loc*2+1);
}


int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int s = 1;
    int e = N;

    for (int i = 1; i <= N; i++){
        int v;
        cin >> v;
        update(s,e,v,i,1);
    }

    for (int i = 1; i < MAX*4; i++) sort(seg[i].begin(), seg[i].end());

    int M;
    cin >> M;
    int last_ans = 0;

    for (int i = 0; i < M; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a = a ^ last_ans;
        b = b ^ last_ans;
        c = c ^ last_ans;
        cout << q(s,e,a,b,c,1) << '\n';
        last_ans = q(s,e,a,b,c,1);
    }

    return 0;
}