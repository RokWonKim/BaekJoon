#include<iostream>
#include<string>

using namespace std;

int fail[10001];
int now;

void make_fail(const string& comp) {
    int j = 0;
    fail[0] = 0;

    for (int i = 1; i < comp.size(); i++) {
        while (j > 0 && comp[j] != comp[i])
            j = fail[j-1];
        
        if (comp[j] == comp[i])
            fail[i] = ++j;
    }
}

int confirm(const string& str, const string& comp, int direct) {
    int j = 0;
    fail[0] = 0;
    int value = 0;

    for (int i = 1; i < str.size()-1; i++) {
        while(j > 0 && str[i] != comp[j]) j = fail[j-1];

        if (str[i] == comp[j]) {
            ++j;
            if (j == comp.size()) {
                if (direct == 0) {
                    value = i-j+1;
                    j = fail[j-1];
                }
                else {
                    now = i-j+1;
                    return i-j+1;
                }   
            }
        }
    }
    now = value;
    return str.size()/2 - value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        int ans = 0;
        cin >> n;

        string str;
        int size = str.size();

        cin >> str;
        str += str;

        //홀수 일때 거꿀로 돌아감
        for (int i = 1; i <= n; i++) {

            string compare;
            cin >> compare;
            int direct;
            if (i % 2 == 1) direct = 0;
            else direct =1;

            make_fail(compare);
            int value = confirm(str, compare, direct);
            ans += value;

            str = str.substr(now, str.size()-now) + str.substr(0, now);
        }

        cout << ans << '\n';

    }

    return 0;
}