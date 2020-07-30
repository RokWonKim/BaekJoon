#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int appear[10];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n,k;
        cin >> n >> k;

        int as, ae, bs,be;
        cin >> as >> ae;
        cin >> bs >> be;

        if (as > bs) {
            swap(as, bs);
            swap(ae, be);
        }

        if (ae <= bs) {
            int diff = bs-ae;
            long long cnt = diff;
            if ( be - as >= k) {
                cout << diff + k << '\n';
                continue;
            }
            cnt += (be-as);
            long long left = cnt + (k - (be-as))*2;


            long long right = 0;
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                right += diff;
                if ( sum + (be-as) >= k) {
                    right += k-sum;
                    sum = k;
                    break;
                }
                right += (be-as);
                sum += (be-as);

                left = min(left, right + (k-sum)*2);
            }

            if (sum < k) {
                right += (k-sum)*2;
            }

            cout << min(right,left) << '\n';
        }
        else if (as <= bs && be <= ae ) {
            long long diff = be-bs;
            if (diff*n >= k) {
                cout << 0 << '\n';
                continue;
            }

            k -= diff*n;
            long long cnt = 0;
            diff = (bs-as) + (ae-be);
            
            for (int i = 0; i < n; i++) {
                if (cnt + diff >= k) {
                    cout << cnt+(k-cnt) << '\n';
                    cnt = k;
                    break;
                }
                cnt += diff;
            }
            if (cnt < k) {
                cnt += (k-cnt)*2;
                cout << cnt << '\n';
            }
        }
        else {
            long long diff = ae-bs;
            if (diff*n >= k) {
                cout << 0 << '\n';
                continue;
            }

            k -= diff*n;
            long long cnt = 0;
            diff = (be-ae) + (bs-as);

            for (int i = 0; i < n; i++) {
                if (cnt + diff >= k) {
                    cout << cnt+(k-cnt) << '\n';
                    cnt = k;
                    break;
                }
                cnt += diff;
            }
            if (cnt < k) {
                cnt += (k-cnt)*2;
                cout << cnt << '\n';
            }
        }        
    }

    return 0;
}
