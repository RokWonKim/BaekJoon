#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int L, C;

vector<char> arr;
vector<char> password;

void print_password() {

    int col = 0;
    int conso = 0;

    for (int i = 0; i < L; i++) {
        char c = password[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            col++;
        else
            conso++;
    }
    
    if( col >= 1 && conso >= 2) {
        for (int i = 0; i < L; i++)
            cout << password[i];
        cout << '\n';
    }
}

void backtracking(int now_location) {

    if (password.size() == L) {
        print_password();
        return;
    }

    for (int i = now_location; i < C; i++) {
        password.push_back(arr[i]);
        backtracking(i+1);
        password.pop_back();
    }

}

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;
    char value;

    for (int i = 0; i < C; i++) {
        cin >> value;
        arr.push_back(value);
    }
    sort( arr.begin(),arr.end() );
    
    backtracking(0);

    return 0;
}