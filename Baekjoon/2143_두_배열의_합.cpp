#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long A[1003];
long long B[1003];
long long T, n, m;
long long ans;

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;

    vector<long long> asum;
    vector<long long> bsum;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> B[i];
    
    
    for (int start = 0; start < n; start++) {
        long long sum = 0;
        for(int end = start; end < n; end++) {
            sum += A[end];
            asum.push_back(sum);
        }
    }
    for (int start = 0; start < m; start++) {
        long long sum = 0;
        for(int end = start; end < m; end++) {
            sum += B[end];
            bsum.push_back(sum);
        }
    }

    sort(asum.begin(), asum.end() );
    sort(bsum.begin(), bsum.end() );

    int a = 0;
    int b = bsum.size()-1;
    while( b >= 0 && a < asum.size() ) {
        if (asum[a] + bsum[b] > T)
            b--;
        else if (asum[a] + bsum[b] < T)
            a++;
        else{
            long long a_between = 0;
            long long now_a = asum[a];
            int i;
            for (i = a; i < asum.size(); i++){
                if (now_a != asum[i]) break;
                a_between++;
            }

            long long b_between = 0;
            long long now_b = bsum[b];
            int j;

            for (j = b; j >= 0; j--) {
                if (now_b != bsum[j]) break;
                b_between++;
            }
            ans += a_between*b_between;
            a = i;
            b = j;
        }

    }

    cout << ans;

    return 0;
}
