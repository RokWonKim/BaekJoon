#include<iostream>
#include<string>
#include<cstring>

using namespace std;

string s;
int fail[1000000];

void make_fail(){
    memset(fail,0,sizeof(fail));

    int j = 0;
    fail[0] = 0;
    for (int i = 1; i < s.size(); i++) {
        while(j > 0 && s[i] != s[j]) j = fail[j-1];
        
        if(s[i] == s[j]) fail[i] = ++j;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin >> s;
        if(s == ".") break;

        make_fail();

        if (fail[s.size() - 1] % (s.size() - fail[s.size() - 1]))
            cout << 1 << '\n';
        else cout << s.size() / ( s.size() - fail[s.size()-1]) << '\n';
    }

    return 0;
}