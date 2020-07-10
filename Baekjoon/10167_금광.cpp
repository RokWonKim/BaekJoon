#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct info {
    int x;
    int y;
    long long w;
};

struct val{
    long long sum;
    long long l_sum;
    long long r_sum;
    long long c_sum;
};

int N;
long long answer;
val seg[3000*4];

vector< info > arr;
vector<int> ycoord;

bool compare(const info& a, const info& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

void update(int start, int end, int index, long long w, int loc) {
    if (start > index || end < index) return;
    else if (start == end) {
        seg[loc].sum += w;
        seg[loc].l_sum += w;
        seg[loc].r_sum += w;
        seg[loc].c_sum += w;
        return;
    }
    
    int mid = (start + end) /2;
    update(start, mid, index, w, loc*2);
    update(mid+1, end, index, w, loc*2+1);
    
    seg[loc].sum = seg[loc*2].sum + seg[loc*2+1].sum;
    seg[loc].l_sum = max(seg[loc*2].l_sum, seg[loc*2].sum+seg[loc*2+1].l_sum);
    seg[loc].r_sum = max(seg[loc*2+1].r_sum, seg[loc*2+1].sum+seg[loc*2].r_sum);
    seg[loc].c_sum = max(seg[loc*2].c_sum, max(seg[loc*2+1].c_sum, seg[loc*2].r_sum+seg[loc*2+1].l_sum));

}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        arr.push_back({x,y,w});
        ycoord.push_back(y);
    }

    sort(arr.begin(), arr.end(), compare);
    sort(ycoord.begin(), ycoord.end());
    ycoord.erase(unique(ycoord.begin(), ycoord.end()), ycoord.end());

    int start = 0;
    int end = ycoord.size()-1;

    for (int i = 0; i < arr.size(); i++) {
        if (i != 0 && arr[i].x == arr[i-1].x) continue;
        for (int j = 0; j < 3000*4; j++) {
            seg[j].sum=0;
            seg[j].c_sum=0;
            seg[j].r_sum=0;
            seg[j].l_sum=0;
        }

        for (int j = i; j < arr.size(); j++) {
            int x = arr[j].x; 
            int y = arr[j].y;
            long long w = arr[j].w;
            int index_y = lower_bound(ycoord.begin(), ycoord.end(), y) - ycoord.begin();
            
            update(start, end, index_y, w, 1);
            if ( j != N-1 && x == arr[j+1].x) continue;
            //long long part = max( max(seg[1].sum, seg[1].c_sum), max(seg[1].l_sum, seg[1].r_sum));
            answer = max(answer, seg[1].c_sum);
        }
    }

    cout << answer << '\n';

    return 0;
}
