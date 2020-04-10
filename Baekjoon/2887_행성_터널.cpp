#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

struct info {
    int x;
    int y;
    int z;
    int vertex;
};
struct line {
    int x;
    int y;
    int weight;
};

int N;
int ans_value;
int union_find[100001];
int tree_rank[100001];
int weight_sum[100001];

bool compare_x(const info& a, const info& b ) { return a.x < b.x; }
bool compare_y(const info& a, const info& b ) { return a.y < b.y; }
bool compare_z(const info& a, const info& b ) { return a.z < b.z; }
bool compare_ans(const line& a, const line& b ) { return a.weight < b.weight; }

int find(int x) {
    if ( x == union_find[x])
        return x;
    return union_find[x] = find(union_find[x]);
}

bool merge(int x, int y, int value) {
    x = find(x);
    y = find(y);
    
    if (x == y) return false;
    
    union_find[x] = y;
    tree_rank[y] += tree_rank[x];
    ans_value += value;
    
    if (tree_rank[y] == N)
        return true;
    
    return false;
}

int main(void) {
    
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    vector<info> arr;
    vector<line> ans;
    
    for (int i=1;i<=N;i++) {
        union_find[i] = i;
        tree_rank[i] = 1;
        
        int a,b,c;
        cin >> a >> b >> c;
        arr.push_back({a,b,c,i});
    }
    
    sort(arr.begin(), arr.end(), compare_x);
    
    for (int i = 1; i < N; i++)
        ans.push_back({arr[i].vertex, arr[i-1].vertex, abs(arr[i].x-arr[i-1].x)});
    
    sort(arr.begin(), arr.end(), compare_y);
    for (int i = 1; i < N; i++)
        ans.push_back({arr[i].vertex, arr[i-1].vertex, abs(arr[i].y-arr[i-1].y)});
    
    sort(arr.begin(), arr.end(), compare_z);
    for (int i = 1; i < N; i++)
        ans.push_back({arr[i].vertex, arr[i-1].vertex, abs(arr[i].z-arr[i-1].z)});
    
    sort(ans.begin(), ans.end(), compare_ans);
    
    for(int i = 0; i < ans.size(); i++) {
        line l = ans[i];
        
        if (merge(l.x, l.y, l.weight)) {
            cout << ans_value;
            break;
        }
    }
    
    return 0;
}
