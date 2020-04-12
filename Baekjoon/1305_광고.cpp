#include<iostream>
#include<vector>
#include<string>

using namespace std;

int N;
string str;
int fail_arr[1000001];

void make_fail() {
    
    int j = 0;
    fail_arr[0] = 0;
    
    for (int i = 1; i < N; i++) {
        while (j != 0 && str[i] != str[j])
            j = fail_arr[j-1];
        if ( str[i] == str[j])
            fail_arr[i] = ++j;
    }
    
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    cin >> str;
    
    make_fail();
    cout << N - fail_arr[N-1];
    
    return 0;
}
