#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[26][26];
int in_num[26];
int out_num[26];
vector<string> word[26][26];


bool checking() {
    int plus = 0;
    int minus = 0;

    for (int i = 0; i < 26; i++) {
        int value = in_num[i] - out_num[i];

        if (value < -1 || value > 1) return false;
        if (value == 1) minus++;
        if (value == -1) plus++;
    }

    return (minus == plus && (minus == 0 || minus == 1));
}

void getcircuit(int start, vector<int>& cir) {
    for (int i = 0; i < 26; i++) {
        while( arr[start][i] > 0) {
            arr[start][i]--;
            getcircuit(i, cir);
        }
    }
    cir.push_back(start);
}

vector<int> getEuler() {
    vector<int> circuit;

    // 트레일
    for (int i = 0; i < 26; i++) {
        //시작점 들어오는 것+1 해줘야 서킷이 됨
        if (out_num[i] == in_num[i] +1) {
            getcircuit(i, circuit);
            return circuit;
        }
    }

    // 서킷
    for (int i = 0; i < 26; i++) {
        if (out_num[i]) {
            getcircuit(i, circuit);
            return circuit;
        }
    }

    return circuit;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(arr, 0, sizeof(arr));
        memset(in_num, 0, sizeof(in_num));
        memset(out_num, 0, sizeof(out_num));
        for (int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++)
                word[i][j].clear();
        int N;
        cin >> N;

        vector<string> v;
        for(int i = 0; i < N; i++) {
            string s;
            cin >> s;

            int start = s[0] - 'a';
            int end = s[s.size()-1] - 'a';
            arr[start][end]++;
            word[start][end].push_back(s);

            out_num[start]++;
            in_num[end]++;
        }

        if (!checking()) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        vector<int> index = getEuler();
        if (index.size() != N+1) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        string answer = "";
        reverse(index.begin(), index.end());
        for (int i= 1; i < index.size(); i++) {
            int start = index[i-1];
            int end = index[i];
            answer += word[start][end].back() + ' ';
            word[start][end].pop_back();
        }

        cout << answer <<'\n';

    }

    return 0;
}