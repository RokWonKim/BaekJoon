#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<map>

using namespace std;

struct trie{
    trie* child[26];
    bool end;

    trie() : end(false) {
        memset(child, 0, sizeof(child));
    }
    ~trie() {
        for (int i = 0; i < 26; i++) delete child[i];
    }

    void insert(const string& s) {
        if (s.size() == 0) end = true;
        else {
            int next = s[0]-'A';
            if (child[next] == 0) child[next] = new trie();
            child[next]->insert(string(s.begin()+1, s.end()));
        }
    }

    bool search(const string& s) {
        if (s.size() == 0) {
            if (end) return true;
            else return false;
        } 
        int next = s[0]-'A';
        if (child[next] == 0) return false;
        else return child[next]->search(string(s.begin()+1, s.end()));
    }
};

bool use[300001];
char arr[4][4];
bool visit[4][4];
int d[8][2] = { {0,1},{1,0},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1} };
int score[9] = {0,0,0,1,1,2,3,5,11};

map<string,int> m;
string word;
int num;
int all_score;
trie* t;

void backtracking(int x, int y, const string& s) {
    if (s.size() <= 8 ) {
        if ( t->search(s) ) {
            if ( use[m[s]] == false) {
                use[m[s]] = true;
                num++;
                all_score += score[s.size()];
                if (word.size() < s.size()) word = s;
                else if (word.size() == s.size()) {
                    if (word > s) word = s; 
                }
            }
        }
    }
    if (s.size() == 8) return;

    for (int i = 0; i < 8; i++) {
        int n_x = x + d[i][0];
        int n_y = y + d[i][1];

        if (n_x < 0 || n_x >= 4 || n_y < 0 || n_y >= 4) continue;
        if (visit[n_x][n_y]) continue;
        visit[n_x][n_y] = true;
        backtracking(n_x,n_y, s+arr[n_x][n_y]);
        visit[n_x][n_y] = false;
    }
}



int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    int count = 1;
    cin >> N;

    t = new trie();
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        t->insert(s);

        m[s] = count++;
    }

    int T;
    cin >> T;
    
    while(T--) {
        word = "";
        num = 0;
        all_score = 0;
        memset(use, false, sizeof(use));

        string a;
        for (int i = 0; i < 4; i++) {
            cin >> a;
            for (int j = 0; j < 4; j++) {
                arr[i][j] = a[j];
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                string part = "";
                part += arr[i][j];
                visit[i][j] = true;
                backtracking(i, j, part);
                visit[i][j] = false;
            }
        }

        cout << all_score << ' ' << word << ' ' << num << '\n';

    }

    return 0;
}