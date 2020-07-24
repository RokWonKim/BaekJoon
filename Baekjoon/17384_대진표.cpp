#include <iostream>

using namespace std;

void d(int start,int end, int count){
    if (start == end) {
        if (count == 1) cout << '#';
        else cout << '.';
        return;
    }

    int next = (end-start+1)/2;
    int mid = (start+end)/2;
    if (count <= next) {
        d(start, mid, count);
        d(mid+1, end, 0);
    }
    else {
        int x = 1;
        while(x*2 <= count-x*2 ) x*=2;

        int left = x;
        int right = count-x;
        if (left < right) swap(left,right);
        if (left > right*2) {
            int diff = left-right*2;
            left -= diff;
            right += diff;
        }
        
        d(start, mid, left);
        d(mid+1, end, right);
    }
    
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    int num = 1;
    while(num < N) num *= 2;

    d(1,num,N);

    return 0;
}