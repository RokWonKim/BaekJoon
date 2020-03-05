#include<iostream>
#include<cmath>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N,c;
    double a,b;
    int spin_direction = 0;
    double spin_num = 1;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;

        spin_direction = abs(spin_direction-c);
        spin_num = (spin_num/a) * b;
    }

    cout << spin_direction << ' ' << (int)spin_num;

    return 0;
}