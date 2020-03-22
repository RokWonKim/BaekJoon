#include<iostream>
#include<string>
#include<vector>

using namespace std;

string A;
string W;
string S;

int arr[150];
int fail[50001];


void fail_func(string &s) {

    fail[0] = 0;

    int j = 0;
    int size = s.size();

    for (int i = 1; i < size; i++) {
        while (j > 0 && s[i] != s[j])
            j = fail[j-1];
        if ( s[i] == s[j] )
            fail[i] = ++j;
    }
}

bool kmp(string &W, string &S) {
    
    int ws = W.size();
    int ss = S.size();
    int j = 0;
    int ans = 0;

    for (int i = 0; i < ss; i++) {
        while ( j > 0 && S[i] != W[j] )
            j = fail[j-1];
        if (S[i] == W[j]) {
            j++;
            if ( j == ws) {
                ans++;
                j = fail[j-2];

                if( ans >= 2)
                    return false;
            }
        }
    }

    if (ans == 1)
        return true;

    return false;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    while(T--) {
        cin >> A;
        cin >> W;
        cin >> S;

        int A_s = A.size();
        int W_s = W.size();
        int S_S = S.size();

        for (int i = 0; i < A_s; i++)
            arr[A[i]] = A[(i+1) % A_s];

        vector<int> ans;

        for (int i = 0; i < A_s; i++) {
            fail_func(W);

            if ( kmp(W, S) )
                ans.push_back(i);

            for (int i = 0; i < W_s; i++)
                W[i] = arr[W[i]];
        }


        if(ans.size() > 1) {
            cout << "ambiguous:";
            for (int i = 0; i < ans.size(); i++)
                cout << ' ' << ans[i];
        }
        else if (ans.size() == 1)
            cout << "unique:" << ' ' << ans[0];
        else
            cout << "no solution";

        cout << '\n';
    }
    
    return 0;
}