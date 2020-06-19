#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct info{
    int x;
    int y;
    int num;

    bool operator < (const info& b) {
        return x < b.x;
    }
};

vector< info > arr;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    int answer = 0;
    int index = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a,b,i+1});
    }
    sort(arr.begin(), arr.end());

    multiset<int> s;
    for (int i = 0; i < arr.size(); i++) {
        int start = arr[i].x;
        int end = arr[i].y;

        s.insert(end);
        set<int>::iterator iter = s.lower_bound(start);
        s.erase(s.begin(), iter);

        if ( answer < s.size()) {
            answer = s.size();
            index = i;
        }
    }

    cout << answer << '\n';
    for (int i = 0; i <= index; i++)
        if ( arr[i].y >= arr[index].x)
            cout << arr[i].num << ' ';

    cout << '\n';


    return 0;
}