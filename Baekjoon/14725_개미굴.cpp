#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
map<string,int> m;
int arr[1001];

struct trie {
    map<string, trie* > m;

    trie() {}
    ~trie() { m.clear(); }

    void insert(const vector<string>& s) {
        if(s.size() == 0) return;

        string next = s[0];
        if (m[next] == NULL) m[next] = new trie();
        m[next]->insert( vector<string>(s.begin()+1, s.end()) );
    }

    void __print(int deep) {

        for (auto now : m) {
            for (int i = 0; i < deep*2; i++) cout << '-';
            cout << now.first << '\n';
            m[now.first]->__print(deep+1);
        }
    }

};

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    trie* t = new trie();
    int N; 
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        vector<string> s(num);
        for (int i = 0; i < num; i++)
            cin >> s[i];

        t->insert(s);
    }

    t->__print(0);

    return 0;
}