#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;

        stack<int> st;
        int i = 0;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else {
                if (st.empty()) break;
                char a = st.top();
                st.pop();
                if( (a == '(' && s[i] == ')') || 
                    (a == '{' && s[i] == '}') || 
                    (a == '[' && s[i] == ']') ) continue;
                else break;
            }
        }
        if (i == s.size() && st.empty()) cout << "YES";
        else cout << "NO";
        cout << '\n';

    }

    return 0;
}