#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;

    int i = -999;
    int j = -999;
    int x = 0;
    int y = 0;
    for (int i = -999; i <= 999; i++) {
        for (int j = -999; j <= 999; j++) {
            if (a*i + b*j == c && d*i + e*j == f) {
                cout << i << ' ' << j <<'\n';
                return 0;
            }
        }
    }


    return 0;
}