#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1000010

using namespace std;

typedef struct Seg{
    long long v = 0;
    long long lazy = 0;
}Seg;

Seg tree[3*MAXN];
long long arr[MAXN];

long long init(int start, int end, int loc) {

    if (start == end) 
        return tree[loc].v = arr[start];
    
    int mid = (start+end)/2;
    return tree[loc].v = init(start, mid, loc*2) + init(mid+1, end, loc*2+1);
}


void update(int part_s, int part_e, int start, int end, int loc, long long plus) {
    
    if (tree[loc].lazy != 0) {
        tree[loc].v += (end-start+1)*tree[loc].lazy;
        if (start != end) {
            tree[loc*2].lazy += tree[loc].lazy;
            tree[loc*2+1].lazy += tree[loc].lazy;
        }
        tree[loc].lazy = 0;
    }

    if(start > part_e || part_s > end) return;
    else if (start >= part_s && part_e >=end) {
        tree[loc].v += (end-start+1)*plus;
        if (start != end) {
            tree[loc*2].lazy += plus;
            tree[loc*2+1].lazy += plus;
        }
        return;
    }

    int mid = (start+end)/2;
    update(part_s, part_e, start, mid, loc*2, plus);
    update(part_s, part_e, mid+1, end, loc*2+1, plus);
    tree[loc].v = tree[loc*2].v + tree[loc*2+1].v;
}

long long sum(int part_s, int part_e, int start, int end, int loc) {

    if (tree[loc].lazy != 0) {
        tree[loc].v += (end-start+1)*tree[loc].lazy;
        if (start != end) {
            tree[loc*2].lazy += tree[loc].lazy;
            tree[loc*2+1].lazy += tree[loc].lazy;
        }
        tree[loc].lazy = 0;
    }

    if(start > part_e || part_s > end) return 0;
    else if (start >= part_s && part_e >=end) 
        return tree[loc].v;
    
    int mid = (start+end)/2;
    return sum(part_s, part_e, start, mid, loc*2)+ sum(part_s, part_e, mid+1, end, loc*2+1);
    
}


int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N,M,K;
    
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    init(1, N, 1);

    for (int i = 0; i < M+K; i++) {
        int a,b,c;
        long long d;
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update(b, c, 1, N, 1, d);
        }
        else {
            cin >> b >> c;
            cout << sum(b, c, 1, N, 1) << '\n';
        }

    }

    return 0;
}