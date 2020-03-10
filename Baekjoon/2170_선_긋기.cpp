#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    int a, b;

    vector< pair<int,int> > arr;
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        if (a > b) swap(a,b);
        arr.push_back({a,b});
    }

    sort(arr.begin(), arr.end());

    int start = -1000000003;
    int end = -1000000003;
    int ans = 0;

    int this_start = 0;
    int this_end = 0;
    for (int i = 0; i < N; i++) {
        tie( this_start, this_end) = arr[i];

        if (start <= this_start && this_end <= end)
            continue;

        ans += this_end - this_start;

        if( end > this_start)
            ans -= end - this_start;
        
        start = this_start;
        end = this_end;
    }

    cout << ans;
    return 0;
}