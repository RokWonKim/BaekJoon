#include<iostream>
#include<vector>

using namespace std;

int r[1001];
int p[1001];
int max_index;
int n;
int incre;

int gcd(int x, int y) {
    if (x % y == 0) return y;
    return gcd(y, x % y);
}

int confirm() {

    incre = p[max_index];
    while(1) {
        int m = gcd(incre, r[max_index]);
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if ( r[i] % (r[max_index]/m) != 0) {
                flag = true;
                break;
            }
        }

        if (flag == false) return m;

        incre++;
    }

    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        
        max_index = 0;
        double value = 1;
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> r[i];
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            if (p[i] > r[i]) {
                if (value > (double)r[i]/p[i]) {
                    max_index = i;
                    value = (double)r[i]/p[i];
                }
            }
        }

        if (value == 1) {
            for (int i = 0; i < n; i++)
                cout << r[i]-p[i] << ' ';
            cout << '\n';
            continue;
        }

        int m = confirm();

        for (int i = 0; i < n; i++) {
            int pow = r[i] / (r[max_index]/m);
            cout << pow*(incre/m) - p[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}