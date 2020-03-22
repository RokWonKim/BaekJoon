#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> arr;
vector<int> s_index;
bool check[9] = {false, };
int fail[200];
int K;
int N;
int ans;

void fail_func(string &s) {

    fail[0] = 0;
    int j = 0;

    for (int i = 1; i < s.size(); i++) {

        while (j > 0 && s[i] != s[j])
            j = fail[j-1];
        if ( s[i] == s[j] )
            fail[i] = ++j;
    }

}

bool kmp() {
    string s = "";

    for (int i = 0; i < s_index.size(); i++)
        s += arr[s_index[i]];

    fail_func(s);
    string s_2 = s + s;

    int j = 0;
    int part_ans = 0;
    int size = s.size();

    for (int i = 0; i < s_2.size()-1; i++) {
        
        while ( j > 0 && s_2[i] != s[j] )
            j = fail[j-1];

        if (s_2[i] == s[j]) {
            if ( ++j == size ) {
                part_ans++;
                j = fail[j-1];
                if (part_ans > K)
                    return false;
            }
        }
    }

    if ( part_ans == K )
        return true;
    
    return false;
}

void backtracking() {

    if (s_index.size() == N) {
        if ( kmp() ) ans++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (check[i] == false) {
            check[i] = true;
            s_index.push_back(i);
            backtracking();

            check[i] = false;
            s_index.pop_back();
        }
    }

}

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    string s = "";

    for (int i = 0; i < N; i++) {
        cin >> s;
        arr.push_back(s);
    }
    cin >> K;

    backtracking();

    cout << ans;

    return 0;
}