#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>

using namespace std;

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int a, b;
    long long ans = 0;
    cin >> N >> M;

    vector< pair<int, int> > come;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        if (a > b)  come.push_back({b,a});
    }

    sort(come.begin(), come.end());

    int start = -1;
    int end = -1;

    int this_start = 0;
    int this_end = 0;
    for (int i = 0; i < come.size(); i++) {
        tie(this_start, this_end) = come[i];

        if (this_end <= end) continue;

        ans += this_end - this_start;

        if (end > this_start)
            ans -= end - this_start;

        start = this_start;
        end = this_end;
    }

    cout << ans*2+M;

    return 0;
}