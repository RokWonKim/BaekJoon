#include<iostream>

using namespace std;

int solve(int x1, int y1, int x2, int y2, int x3, int y3) {
    int answer = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
    if (answer > 0) return 1;
    if (answer == 0) return 0;
    else return -1;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int x1,y1, x2,y2, x3,y3, x4,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    if (solve(x1,y1,x4,y4,x3,y3) == 0 || solve(x3,y3,x2,y2,x4,y4) == 0) cout << 0;
    else if (solve(x1,y1,x2,y2,x3,y3) == 0 || solve(x1,y1,x2,y2,x4,y4) == 0) cout << 0;
    else if (solve(x1,y1,x2,y2,x3,y3) == solve(x1,y1,x2,y2,x4,y4)) cout << 0;
    else cout << 1;

    return 0;
}