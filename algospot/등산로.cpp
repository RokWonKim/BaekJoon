#include <iostream>
#include <utility>

using namespace std;

pair<int,int> seg[400001];
int arr[100001];
int n, q;

pair<int,int> segment_init(int index, int left, int right) {
    if (left == right)
        seg[index] = {arr[left],arr[left]};
    else {
        pair<int,int> left_seg = segment_init(index*2+ 1, left, (left+right)/2);
        pair<int,int> right_seg = segment_init(index*2 + 2, (left+right)/2+1, right);
        seg[index] = {min(left_seg.first, right_seg.first), max(left_seg.second, right_seg.second)};
    }

    return seg[index];
}

pair<int,int> diff(int index,int start, int end, int left, int right) {
    if (end < left || start > right)
        return {200001, -1};
    else if ( start >= left && end <= right)
        return seg[index];
    else {
        pair<int,int> left_seg = diff(index*2+1, start, (start+end)/2, left, right);
        pair<int,int> right_seg = diff(index*2+2, (start+end)/2+1, end, left, right);
        return {min(left_seg.first,right_seg.first), max(left_seg.second,right_seg.second)};
    }
    
}


int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> q;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        segment_init(0, 0, n-1);

        for (int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            pair<int,int> answer = diff(0, 0, n-1, a, b);
            cout << answer.second - answer.first << '\n';
        }
    }

    return 0;
}