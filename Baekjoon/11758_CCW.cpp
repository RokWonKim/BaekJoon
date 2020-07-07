#include <iostream>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int answer = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
    if (answer == 0) cout << 0;
    else if (answer > 0) cout << 1;
    else cout << -1;
    cout <<'\n';

    return 0;
}