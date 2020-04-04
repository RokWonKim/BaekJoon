#include<iostream>

using namespace std;

long long ans[2][2];
long long rem[2][2];

void calcul(long long a[2][2], long long b[2][2] ) {
    
    long long part[2][2];
    
    part[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % 1000000;
    part[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % 1000000;
    part[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % 1000000;
    part[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % 1000000;
    
    
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            a[i][j] = part[i][j];
    
}

int main(void) {
    
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    ans[0][0] = ans[1][1] = rem[0][1] = rem[1][0] = rem[0][0] = 1;
    
    long long n;
    cin >> n;
    if (n == 0) cout << 0;
    else if (n == 1) cout << 1;
    else {
        n--;
        
        while ( n >= 1) {
            if (n%2 == 1)
                calcul(ans, rem);
            calcul(rem,rem);
            n /= 2;
        }
        cout << ans[0][0];
    }
    
    
    return 0;
}
