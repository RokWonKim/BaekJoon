#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 1*1000*1000*1000+7;
long long arr[1000001];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long answer = 1;
    long long diff = 1;
    arr[0] = 1;

    for (int i = 1; i <= n; i++) {
        arr[i] = (arr[i-1]*i)%INF;
        if (i != n) diff = (diff*2) % INF;
    }

    cout << (arr[n]+INF-diff) %INF <<'\n';
    
   return 0;
}
