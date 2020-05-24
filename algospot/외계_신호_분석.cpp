#include<iostream>
#include<cmath>

using namespace std;



int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int k, n;
        int ans = 0;
        cin >> k >> n;

        long long sum = 1984;
        int left = 0;
        int right = 0;
        long long real_right_value = (1983 * 214013 + 2531011) % (long long)pow(2,32);;
        long long real_left_value = (1983 * 214013 + 2531011) % (long long)pow(2,32);;

        long long left_sign = 1984;

        while(right < n) {
            if (sum == k) {
                ans++;
                right++;
                sum += real_right_value % 10000 + 1;

                real_right_value = (real_right_value * 214013 + 2531011) % (long long)pow(2,32);
            }
            else if (sum < k || left == right){
                right++;
                sum += real_right_value % 10000 + 1;

                real_right_value = (real_right_value * 214013 + 2531011) % (long long)pow(2,32);
            }
            else {
                left++;
                sum -= left_sign;

                left_sign = real_left_value % 10000 + 1;
                real_left_value = (real_left_value * 214013 + 2531011) % (long long)pow(2,32);
            }
        }

        cout << ans <<'\n';

    }



    return 0;
}