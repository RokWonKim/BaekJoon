#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;


vector<pair<int,int>> arr;
vector<int> coord;

long long seg[75000 * 4];

bool compare(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

void insert(int start, int end, int index, int loc) {
    if( start > index || end < index) return;
    else if (start == end) {
        seg[loc] += 1;
        return;
    }

    int mid = (start+end)/2;
    insert(start,mid,index, loc*2);
    insert(mid+1,end,index, loc*2+1);
    seg[loc] = seg[loc*2] + seg[loc*2+1];
}

long long sum(int start, int end, int a, int b, int loc) {
    if (a > end || b < start) return 0;
    else if (a <= start && end <= b) return seg[loc];

    int mid = (start+end)/2;
    return seg[loc] = sum(start,mid,a,b,loc*2) + sum(mid+1,end,a,b,loc*2+1);
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(seg, 0, sizeof(seg));
        arr.clear();
        coord.clear();
        int N;
        long long answer = 0;
        cin >> N;

        for (int i = 0; i < N; i++) {
            int a,b;
            cin >> a >> b;
            arr.push_back({a,b});
            coord.push_back(b);
        }
        sort(arr.begin(), arr.end(), compare);

        sort(coord.begin(), coord.end());
        coord.erase(unique(coord.begin(), coord.end()) , coord.end());
        

        int start = 0;
        int end = coord.size()-1;

        for (int i = arr.size()-1; i >= 0; i--) {
            int y = arr[i].second;

            int loc_index = (upper_bound(coord.begin(), coord.end(), y) - coord.begin())-1;

            answer += sum(start,end, 0, loc_index, 1);
            insert(start, end, loc_index, 1);
        }

        cout << answer << '\n';
    }

    return 0;
}