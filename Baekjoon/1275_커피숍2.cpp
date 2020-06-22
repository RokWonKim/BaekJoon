#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100001

using namespace std;

int arr[MAXN];
long long segment[4*MAXN];

long long init(int start, int end, int loc) {
    if (start == end) return segment[loc] = arr[start];
    
    int mid = (start+end)/2;
    return segment[loc] = init(start, mid, loc*2)+init(mid+1, end, loc*2+1);
}

long long sum(int start, int end, int a, int b, int loc) {
    if (end < a || start > b) return 0;
    else if (a <= start && end <= b) return segment[loc];

    int mid = (start+end)/2;
    return sum(start,mid,a,b,loc*2) + sum(mid+1,end,a,b,loc*2+1);
}

void update(int start, int end, int index, int value, int loc) {
    if (start > index || end < index) return;
    else if (start == end) segment[loc] = value;
    else {
        int mid = (start+end)/2;
        update(start, mid, index, value, loc*2);
        update(mid+1, end, index, value, loc*2+1);

        segment[loc] = segment[loc*2] + segment[loc*2+1];
    }
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) cin >> arr[i];
    init(1, N, 1);

    for (int i = 0; i < Q; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        
        if (a > b) swap(a,b);
        cout << sum(1, N, a, b, 1) << '\n';
        update(1, N, c, d, 1);
    }

    return 0;
}