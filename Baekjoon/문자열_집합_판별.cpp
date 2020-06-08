#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

struct trie{
    trie* go[26];
    trie* fail;
    bool last;

    trie() : fail(nullptr), last(false) {
        fill(go, go+26, nullptr);
    }
    ~trie() {
        for(int i = 0; i < 26; i++)
            if (go[i]) delete go[i];
    }

    void insert(const string& key) {
        if (key.size() == 0) last = true;
        else {
            int next = key[0] - 'a';
            if (!go[next]) go[next] = new trie();
            go[next]->insert(string(key.begin()+1, key.end()));
        }
    }
};

bool search_string(const string& s, trie* root) {

    trie* now = root;
    for (int i = 0; i < s.size(); i++){
        int next = s[i] - 'a';

        while (now != root && !now->go[next])
            now = now->fail;

        if (now->go[next]) now = now->go[next];

        if (now->last) return true;
    }

    return false;
} 

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    trie *root = new trie();

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        root->insert(s);
    }

    queue<trie*> q;
    q.push(root);
    while(!q.empty()) {
        trie* now = q.front();
        q.pop();
        
        for (int i = 0; i < 26; i++) {
            trie* next = now->go[i];
            if(next == NULL) continue;

            if (now == root) next->fail = root;
            else {
                trie* looking = now->fail;

                while(looking != root && !looking->go[i])
                    looking = looking->fail;
                
                if (looking->go[i]) looking = looking->go[i];
                next->fail = looking;
            }
            if (next->fail->last == true) next->last = true;
            q.push(next);
        }
    }

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string s;
        cin >> s;

        if (search_string(s,root)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    delete root;

    return 0;
}