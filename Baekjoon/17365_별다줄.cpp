#include <iostream>
#include <cstring>

using namespace std;

struct trie {
    trie* arr[26] = {nullptr, };
    int num;

    trie() {
        num = 0;
    }
    ~trie() {
        for (int i = 0; i < 26; i++) delete arr[i];
    }

    void insert(const string& s) {
        if (s.size() == 0) return;
        
        int next = s[0] - 'a';
        if (!arr[next]) arr[next] = new trie();
        (arr[next]->num) += 1;
        arr[next]->insert(string(s.begin()+1, s.end()));
    }
};

const int MOD = 1*1000*1000*1000+7;

long long dp[200001];
string s;
int siz;
trie* t;

long long solve(int index) {
    if (index == siz) return 1;

    long long &value = dp[index];
    if (value != -1) return value;

    value = 0;
    trie* r = t;

    for (int i = index; i < siz; i++) {
        int next = s[i]-'a';

        if (r->arr[next] != nullptr) {
            r = r->arr[next];
            value = (value + (r->num) * solve(i+1) ) % MOD;
        }
        else break;
    }

    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    int N;
    cin >> N;

    t = new trie();
    for (int i = 0; i < N; i++) {
        string a;
        cin >> a;
        t->insert(a);
    }

    cin >> s;
    siz = s.size();

    cout << solve(0) << '\n';

    return 0;
}