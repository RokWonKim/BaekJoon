#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int solve(const string& s, int c) {
    if (s.size() == 1) {
        if (s[0] == c) return 0;
        return 1;
    }

    int mid = s.size() /2;
    int part_1 = solve( s.substr(0,mid), c+1) + (mid - count(s.begin()+mid,s.end(),c));
    int part_2 = solve( s.substr(mid, s.size()-mid), c+1) + (mid - count(s.begin(), s.begin()+mid, c));

    return min(part_1, part_2);
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N;
        string s;
        cin >> N >> s;

        cout << solve(s, 'a') << '\n';
    }

    return 0;
}