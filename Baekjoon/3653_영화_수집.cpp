#include <iostream>
#include <vector>

using namespace std;

int seg[200001*4];
int ver_num[200001];

int init(int start, int end, int loc) {
    if (start == end) return seg[loc] = 1;
    
    int mid = (start+end)/2;
    return seg[loc] = init(start, mid, loc*2) + init(mid+1, end, loc*2+1);
}

int sum(int start, int end, int a, int b, int loc) {
    if (end < a || start > b) return 0;
    else if( a <= start && b >= end) return seg[loc];

    int mid = (start+end)/2;
    return sum(start,mid,a,b,loc*2) + sum(mid+1,end,a,b,loc*2+1);
}

void update(int start, int end, int ind, int loc) {
    if (start > ind || end < ind) return;
    else if(start == end) {
        seg[loc] = 0;
        return;
    }
    int mid = (start + end)/2;
    update(start, mid, ind, loc*2);
    update(mid+1, end, ind, loc*2+1);

    seg[loc] = seg[loc*2] + seg[loc*2+1];
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N, M;
        cin >> N >> M;
        int end_num = N;
        init(1, N+M, 1);
        for (int i = 1; i <= N; i++) ver_num[i] = N-(i-1);

        for (int i = 0; i < M; i++) {
            int num;
            cin >> num;
            cout << sum(1, N+M, ver_num[num], end_num, 1) - 1 << ' ';

            update(1, N+M, ver_num[num], 1);
            end_num++;
            ver_num[num] = end_num;
            
        }
        cout << '\n';

    }

    return 0;
}