#include<iostream>

using namespace std;

const int basic = 500000;

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N,x,y, x1, y1, x2, y2;
    int x_line[1000002] = {0, };
    int y_line[1000002] = {0, };
    int ans = 0;

    cin >> N;
    cin >> x >> y;
    x1 = x;
    y1 = y;

    for(int i = 1; i < N; i++) {
        cin >> x2 >> y2;
        if ( x2 == x1) {
            y_line[min(y1,y2) + basic]++;
            y_line[max(y1,y2) + basic]--;
        }
        else{
            x_line[min(x1,x2) + basic]++;
            x_line[max(x1,x2) + basic]--;
        }
        x1 = x2;
        y1 = y2;
    }

    if (x == x1) {
        y_line[min(y,y1) + basic]++;
        y_line[max(y,y1) + basic]--;
    }
    else {
        x_line[min(x1,x) + basic]++;
        x_line[max(x1,x) + basic]--;
    }

    
    for(int i = 1; i < 1000001; i++) {
        x_line[i] += x_line[i-1];
        y_line[i] += y_line[i-1];
        ans = max(ans, max(x_line[i],y_line[i]));
    }

    cout << ans;

    return 0;
}