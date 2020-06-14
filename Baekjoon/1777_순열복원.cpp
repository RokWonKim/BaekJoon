#include <iostream>

using namespace std;

int N;
int arr[100001];
int input_arr[100001];
int seg[4*100000];

void update(int value, int index, int start, int end, int loc) {
    if (start > index || end < index) return;
    if (start == end) {
        seg[loc] = value;
        return;
    }

    int mid = (start+end)/2;
    update(value, index, start, mid, loc*2+1);
    update(value, index, mid+1, end, loc*2+2);
    seg[loc] = seg[loc*2+1] + seg[loc*2+2];
}

int sum(int value, int start, int end, int loc) {
    int mid = (start+end)/2;

    if (start == end) return start;
    
    else if (value > seg[loc*2+2])
        return sum(value-seg[loc*2+2], start, mid, loc*2+1);
    
    return sum(value, mid+1, end, loc*2+2);
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> input_arr[i];

    for (int i = 0; i < N; i++) update(1,i+1,1,N,0);

    for (int i = N-1; i >= 0; i--) {
        int answer = sum(input_arr[i]+1, 1,N,0);
        arr[answer] = i+1;
        update(0,answer,1,N,0);
    }

    for (int i = 1; i <= N; i++)
        cout << arr[i] << ' ';

    return 0;
}