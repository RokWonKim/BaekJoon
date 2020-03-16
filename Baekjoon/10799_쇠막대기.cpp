#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    char a;
    int ans = 0;
    int open_door = 0;

    string arr = "";
    
    cin >> arr;


    char before = arr[0];
    if ( arr[0] == '(')
        open_door++;

    for(int i = 1; i < arr.size(); i++) {
        if (arr[i] == '(')
            open_door++;
        else {
            if (before == '(')
                ans += --open_door;
            else {
                ans++;
                open_door--;
            }
        }
        before = arr[i];
    }

    cout << ans;

    return 0;
}