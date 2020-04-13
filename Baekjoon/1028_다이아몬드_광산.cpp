#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int arr[751][751];
int left_down[751][751];
int right_down[751][751];

int main(void) {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int R, C;
    int ans = 0;
    string str;
    cin >> R >> C;
    
    for(int i = 0; i < R; i++) {
        cin >> str;
        for (int j = 0; j < C; j++)
            arr[i][j] = str[j]-'0';
    }
    
    for (int i = R-1; i >= 0; i--) {
        for(int j = C-1; j >= 0; j--) {
            if (arr[i][j] == 1) {
                left_down[i][j] = 1;
                right_down[i][j] = 1;
                
                // i+1 , j-1 => left
                // i+1 , j+1 => right
                if (i+1 < R && j-1 >= 0)
                    left_down[i][j] += left_down[i+1][j-1];
                if (i+1 < R && j+1 < C)
                    right_down[i][j] += right_down[i+1][j+1];
            }
        }
    }
    
    for (int i = 0 ; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == 1) {
                int x = min(left_down[i][j],right_down[i][j]);
                
                for (int k = x-1; k >= 0; k--) {
                    if (k < ans) break;
                    if (right_down[i+k][j-k] > k && left_down[i+k][j+k] > k) {
                        ans = max(ans, k+1);
                        break;
                    }
                }
            }
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}
