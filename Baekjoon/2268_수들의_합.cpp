#include <iostream>

using namespace std;

long long seg[4*1000000];

void insert(int value,int index, int start, int end, int loc){
    if (index < start || index > end) return;
    if (start == end) {
        seg[loc] = value;
        return;
    }

    int mid = (start+end)/2;
    insert(value, index, start, mid, loc*2+1);
    insert(value, index, mid+1, end, loc*2+2);
    seg[loc] = seg[loc*2+1] + seg[loc*2+2];

    return;
}

long long sum(int a, int b, int start, int end, int loc) {
    if (start > b || end < a) 
        return 0;
    else if ( a <= start && b >= end)
        return seg[loc];
    else {
        int mid = (start+end)/2;
        return sum(a,b,start,mid,loc*2+1) + sum(a,b,mid+1,end,loc*2+2);
    }
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            if (b > c) swap(b,c);
            cout << sum(b-1,c-1,0, N-1, 0) <<'\n';
        }
        else
            insert(c, b-1, 0, N-1, 0);
            
    }
}

