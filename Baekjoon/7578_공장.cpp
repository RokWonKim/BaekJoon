#include <cstdio>
#include <vector>

using namespace std;

struct Seg{
    long long value;
    long long lazy;
};

int arr[1000001];
Seg segtree [4*500000];

//특정 구간에 모두 값을 넣어줘야할때 쓰는 lazy propagation
void update(int part_s, int part_e, int start, int end, int loc, int plus) {

    if (segtree[loc].lazy != 0) {
        segtree[loc].value += segtree[loc].lazy;
        if (start != end) {
            segtree[loc*2+1].lazy += segtree[loc].lazy;
            segtree[loc*2+2].lazy += segtree[loc].lazy;
        }
        segtree[loc].lazy = 0;
    }

    if (start > part_e || end < part_s)
        return;
    else if (part_s <= start && part_e >= end) {
        segtree[loc].value += plus;
        if (start != end) {
            segtree[loc*2+1].lazy += plus;
            segtree[loc*2+2].lazy += plus;
        }
        return;
    }
    
    int mid = (start+end)/2;
    update(part_s, part_e, start, mid, loc*2+1, plus);
    update(part_s, part_e, mid+1, end, loc*2+2, plus);

    segtree[loc].value = segtree[loc*2+1].value + segtree[loc*2+2].value;
}


int select(int index, int start, int end, int loc) {

    if (segtree[loc].lazy != 0) {
        segtree[loc].value += segtree[loc].lazy;
        if (start != end) {
            segtree[loc*2+1].lazy += segtree[loc].lazy;
            segtree[loc*2+2].lazy += segtree[loc].lazy;
        }
        segtree[loc].lazy = 0;
    }

    if (index < start || index > end)
        return 0;
    else if (start == end)
        return segtree[loc].value;
    
    int mid = (start+end)/2;
    return select(index, start, mid, loc*2+1) + select(index, mid+1, end, loc*2+2);
}


int main(void) {

    vector<int> v;
    long long answer = 0;

    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }

    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        arr[a] = i;
    }

    for (int i = 0; i < N; i++) {
        int a = arr[v[i]];
        answer += select(a, 0, N-1, 0);
        update(0, a, 0, N-1, 0, 1);
    }

    printf("%lld\n", answer);

    return 0;
}