#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int arr[100001];
vector<int> answer;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        answer.clear();
        int N;
        string s1;
        string s2;
        
        cin >> N;
        cin >> s1;
        cin >> s2;


        for (int i = 0; i < N; i++) {
            if (s1[0] == s2[N-i-1]) {
                answer.push_back(1);
                if (s1[0] == '0') s1[0]= '1';
                else s1[0] = '0'; 
            }
            
            for (int j = 0; j < N-i; j++)  {
                if (s1[j] == '0') s1[j]= '1';
                else s1[j] = '0'; 
            }
            
            int start = 0;
            int end = (N-i-1);
            while(start < end) {
                swap(s1[start++],s1[end--]);
            }
        
            answer.push_back(N-i);
        }

        cout << answer.size() << ' ';
        for (int i : answer) cout << i << ' ';
        cout << '\n';

    }


    return 0;
}