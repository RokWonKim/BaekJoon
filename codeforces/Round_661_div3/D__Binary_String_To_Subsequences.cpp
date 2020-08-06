#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int answer[2*100000+2];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        string s = "";
        cin >> n;
        cin >> s;
        queue<int> zero;
        queue<int> one;

        int number = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (one.size() == 0) {
                    answer[i] = number;
                    zero.push(number);
                    number++;
                }
                else {
                    int now = one.front();
                    one.pop();
                    answer[i] = now;
                    zero.push(now);
                }   
            }
            else {
                if (zero.size() == 0) {
                    answer[i] = number;
                    one.push(number);
                    number++;
                }
                else {
                    int now = zero.front();
                    zero.pop();
                    answer[i] = now;
                    one.push(now);
                }

            }
        }

        cout << zero.size() + one.size() << '\n';
        for (int i = 0; i < n; i++) cout << answer[i] << ' ';
        cout << '\n';



    }

    return 0;
}