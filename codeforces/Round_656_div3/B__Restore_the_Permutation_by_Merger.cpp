#include <iostream>
#include <cstring>
 
using namespace std;
 
int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        
        int arr[2*N];
        for (int i = 0; i < 2*N; i++)
            cin >> arr[i];
 
        bool check[N+1];
        memset(check, false, sizeof(check));
 
        for (int i = 0; i < 2*N; i++) {
            if (!check[arr[i]]) {
                cout << arr[i] << ' ';
                check[arr[i]] = true;
            }
        }
 
        cout << '\n';
    }
 
 
    return 0;
}