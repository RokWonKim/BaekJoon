#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int Answer;
bool ok[100001];

int main(int argc, char** argv)
{
    int T, test_case;
    
    cin >> T;
    for(test_case = 0; test_case < T; test_case++)
    {
        
        int n, m;
        cin >> n >> m;
        
        Answer = n;
        
        memset(ok, false, sizeof(ok));
        
        vector< set<int> > arr(n+1);
        
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            
            if (arr[b].find(a) == arr[b].end())
                arr[a].insert(b);
            else {
                if (ok[a] != true) {
                    ok[a] = true;
                    Answer--;
                }
                if (ok[b] != true) {
                    ok[b] = true;
                    Answer--;
                }
            }
        }
        
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;
}
