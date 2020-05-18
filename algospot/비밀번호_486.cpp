#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;


const int INF = 10000001;
int min_number[INF];
int min_pow[INF];
int numbers[INF];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for (int i = 2; i <= sqrt(INF); i++)
        for (int j = i*i; j < INF; j += i)
            if (min_number[j] == 0)
                min_number[j] = i;

    
    for (int i = 2; i < INF; i++) {
        if (min_number[i] == 0) {
            min_pow[i] = 1;
            numbers[i] = 2;
            min_number[i] = i;
        }
        else {
            int mod = min_number[i];
            int remain = i/mod;

            if (mod != min_number[remain])
                min_pow[i] = 1;
            else
                min_pow[i] = min_pow[remain]+1;

            numbers[i] = ( numbers[remain] / min_pow[i] ) * (min_pow[i]+1);
        }
    }
    
    numbers[1] = 1;
    while(T--) {
        int n, lo, hi;
        int ans = 0;
        cin >> n >> lo >> hi;

        for (int i = lo; i <= hi; i++)
            if (numbers[i] == n) ans++;

        cout << ans <<'\n';

    }

    return 0;
}