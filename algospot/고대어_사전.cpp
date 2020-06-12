#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int link_num[26];
vector<int> arr[26];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(link_num, 0, sizeof(link_num));
        for (int i = 0; i < 26; i++) arr[i].clear();
        string answer = "";

        int N;
        cin >> N;
        vector<string> v;
        for (int i = 0; i < N; i++) {
            string now = "";
            cin >> now;
            v.push_back(now);
        }
        
        for (int i = 1; i < N; i++) {
            string now = v[i-1];
            string value = v[i];
            for (int j = 0; j < min(now.size(),value.size()); j++) {
                if (now[j] != value[j]) {
                    int a = now[j] - 'a';
                    int b = value[j] - 'a';
                    arr[a].push_back(b);
                    link_num[b]++; 
                    break;
                }
            }
        }

        queue<int> q;

        for (int i = 0; i < 26; i++)
            if (link_num[i] == 0) q.push(i);

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            answer += char(cur + 'a');

            for (int next : arr[cur]) {
                link_num[next]--;
                if (link_num[next] == 0) q.push(next);
            }
        }
        bool flag = false;
        for (int i = 0; i <26; i++) {
            if(link_num[i] != 0) {
                cout << "INVALID HYPOTHESIS\n";
                flag = true;
                break;
            }
        }
        if(!flag) cout << answer <<'\n';
    }

    return 0;
}