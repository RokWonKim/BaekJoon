#include <iostream>

using namespace std;

const int INF = 1*1000*1000*1000+1;

int arr[100002];
int seg[4*100000];

int make_seg(int start, int end, int loc) {
    if (start == end) seg[loc] = start;
    else {
        int mid = (start+end)/2;
        int in_1 = make_seg(start, mid, loc*2+1);
        int in_2 = make_seg(mid+1, end, loc*2+2);
        if (arr[in_1] < arr[in_2]) seg[loc] = in_1;
        else seg[loc] = in_2;
    }

    return seg[loc];
}

int query(int v_a, int v_b, int start, int end, int loc) {
    if (v_b < start || v_a > end )
        return 100001;
    else if (v_a <= start && v_b >= end)
        return seg[loc];
    else {
        int mid = (start+end)/2;
        int in_1 = query(v_a, v_b, start, mid, loc*2+1);
        int in_2 = query(v_a, v_b, mid+1, end, loc*2+2);
        
        return (arr[in_1] < arr[in_2]?in_1:in_2);
    }

    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    arr[100001] = INF;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    make_seg(0, N-1, 0);
    for (int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;
        cout << arr[query(a-1,b-1,0,N-1,0)] << '\n';
    }

    return 0;
}