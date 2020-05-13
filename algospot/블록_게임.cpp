#include<iostream>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

char dp[1 << 25];
vector<int> possible;

char solve(int token) {

    char &value = dp[token];
    if (value != -1) return value;

    value = 0;
    for (int a : possible) {
        if ( (token & a) == 0) {
            if ( solve(token | a) == 0 ){
                value = 1;
                break;
            }
        }
    }

    return value;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(dp, -1, sizeof(dp));
        possible.clear();
        string s;
        int value = 0;
        for(int i = 0; i < 5; i++) {
            cin >> s;
            for (int j = 0; j < 5; j++) {
                if (s[j] == '#') {
                    value += (1 << (i * 5 + j));
                }
            }
        }
        // 3개 넣는 것은 4가지 방법
        // 2개 넣는 것은 2가지 방법
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                possible.push_back( (1 << (i*5 + j)) + (1 << ( (i+1)*5 + j)) + (1 << ( (i+1)*5+j+1)) );
                possible.push_back( (1 << (i*5 + j)) + (1 << ( i*5 + j+1)) + (1 << ( (i+1)*5+j+1)) );
                possible.push_back( (1 << (i*5 + j)) + (1 << ( i*5 + j+1)) + (1 << ( (i+1)*5 + j)) );
                possible.push_back( (1 << (i*5 + j+1)) + (1 << ( (i+1)*5 + j)) + (1 << ( (i+1)*5+j+1)) );

                possible.push_back( (1 << (i*5 + j)) + (1<<(i*5 + j+1)) );
                possible.push_back( (1 << (i*5 + j)) + (1<<( (i+1)*5 + j)) );
            }
        }
        for (int i = 0; i < 4; i++) {
            possible.push_back( (1 << ( 20 + i)) + (1<<(20 + i+1)) );
            possible.push_back( (1 << (i*5 + 4)) + (1<<( (i+1)*5 + 4)) );
        }

        int ans = solve(value);
        if (ans) cout << "WINNING\n";
        else cout << "LOSING\n";
    }

    



    return 0;
}