#include<iostream>
#include<set>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        set<pair<int,int>> s;
        int n,sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;

            if (s.empty()) {
                s.insert({a,b});
                sum++;
                continue;
            }
            
            set<pair<int,int>>::iterator c = s.lower_bound({a,b});

            if (c == s.end() || c->second < b) {

                if (c != s.begin()) {
                    --c;
                    while(1) {
                        if (c->second > b) break;
                        else if (c == s.begin()) {
                            s.erase(c);
                            break;
                        }
                        else {
                            set<pair<int,int>>::iterator it = c;
                            --it;
                            s.erase(c);
                            c =it;
                        } 
                    }
                }
                s.insert({a,b});
            }
            sum += s.size();

        }

        cout << sum << '\n';
    }

    return 0;
}