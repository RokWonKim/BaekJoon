#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct trie {
    trie* child[26];
    int prefer;
    int index;
    int this_prefer;
    // 끝나는 구간인지
    bool terminal;
    trie() : terminal(false), prefer(0), index(-1), this_prefer(0) {
        memset(child, 0, sizeof(child));
    }
    ~trie() {
        for (int i = 0; i < 26; i++)
            if (child[i]) delete child[i];
    }

    void insert(const string& key, int value) {
        
        if (key.size() == 0) {
            terminal = true;
            this_prefer = value;
            if (value > prefer ) {
                prefer = value;
                index = -1;
            }
        }
        else {
            int next = key[0] - 'A';

            if (value > prefer) {
                index = next;
                prefer = value;
            }
            else if (value == prefer && index > next) {
                index = next;
            }
            
            if (child[next] == NULL) child[next] = new trie();
            child[next]->insert( string(key.begin()+1, key.end()) , value);
        }
    }

    bool find(const string& key) {
        if (key.size() == 0 && terminal) return true;
        else if (key.size() == 0) return false;

        int next = key[0] - 'A';
        if (child[next] == NULL) return false;
        return child[next]->find( string(key.begin()+1, key.end())); 
    }

    bool sequen(const string& key, const string& real) {
        if (real.size() == 0) {
            if (this_prefer != prefer) return false;
            return true;
        }
        else if (key.size() == 0) {
            if (index == -1) return false;
            else if (index == real[0]-'A')
                return child[index]->sequen(key,string(real.begin()+1, real.end()));
            else return false;
        }
        else {
            int next = key[0] - 'A';
            return child[next]->sequen(string(key.begin()+1, key.end()), string(real.begin()+1, real.end()) );
        }
    }

};

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N, M;
        cin >> N >> M;
        trie* dict = new trie();
        int answer = M-1;

        for (int i = 0; i < N; i++) {
            string s;
            int num;
            cin >> s >> num;
            dict->insert(s, num);
        }

        for (int i = 0; i < M; i++) {
            string s;
            cin >> s;

            if (s.size() == 1)
                answer++;
            //없으면 문자열 길이 만큼+
            else if ( dict->find(s) == false) 
                answer += s.size();
            else {
                int j = 0;
                bool flag = false;

                for (j = 0; j < s.size()-1; j++) {
                    if (dict->sequen(s.substr(0,j+1), s)) {
                        flag = true;
                        break;
                    } 
                }

                if (!flag) answer += s.size();
                else answer += j+2;
            }
        }

        cout << answer <<'\n';

    }

    return 0;
}