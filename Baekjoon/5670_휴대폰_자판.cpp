#include <cstdio>
#include <map>
#include <vector>
#include <string>

using namespace std;

double answer;

struct trie {
    map<char, trie*> m;
    bool last;

    trie() : last(false) {}
    ~trie() {m.clear();}

    void insert(const string& s) {
        if (s.size() == 0) {
            last = true;
            return;
        }
        char next = s[0];
        if (m[next] == NULL) m[next] = new trie();
        m[next]->insert(string(s.begin()+1, s.end()));
    }

    void cnt(int deep) {
        trie* t = this;
        
        while( !(t->last) && (t->m).size() == 1) {
            for (auto v : (t->m)) {
                t = (t->m)[v.first];
                break;
            }
        }

        if (t->last) answer += deep;
        for (auto v : t->m) (t->m)[v.first]->cnt(deep+1);

        delete t;
    }


};

int main(void) {
    int N;

    while(scanf("%d",&N) == 1) {
        answer = 0;

        trie* t = new trie();
        for (int i = 0; i < N; i++) {
            char c[80];
            scanf("%s", c);
            string s = "";

            for (int i = 0; c[i] != '\0'; i++) s += c[i];
            
            t->insert(s);
        }

        for (auto v : t->m) t->m[v.first]->cnt(1);

        printf("%.2lf\n", answer/N);

        delete t;
    }

    return 0;
}