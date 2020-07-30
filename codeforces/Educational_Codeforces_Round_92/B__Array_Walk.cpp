#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#define MAX 100001

using namespace std;

int arr[MAX];
int sum[MAX];
int maxtwo[MAX];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {

        int n,k,z;
        int answer = 0;
        cin >> n >> k >> z;

        for (int i = 0; i < n; i++) cin >> arr[i];
        maxtwo[0] = 0;
        sum[0] = arr[0];

        for (int i = 1; i < n; i++) {
            maxtwo[i] = max(maxtwo[i-1], arr[i]+arr[i-1]);
            sum[i] = sum[i-1] + arr[i];
        }

        for (int i = k; i > 0 && z*2 >= k-i; i--) {
            if ( (k-i)%2 == 0)
                answer = max(answer, sum[i] + (k-i)/2*maxtwo[i]);
            else
                answer = max(answer, arr[i-1] + sum[i] + (k-i)/2*maxtwo[i]);
        }

        cout << answer << '\n';
    }

    return 0;
}