#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

struct info{
    int v1;
    int v2;
    double value;
};

struct vertex_info{
    int x;
    int y;
    int r;
};

int W, N;
int union_find[1005];


bool compare_vertex(const vertex_info& a, const vertex_info& b ) {return a.x < b.x;}
bool compare_value(const info& a, const info& b ) {return a.value < b.value;}

double distance( int x1, int y1, int x2, int y2 ) {
    return sqrt( (long long)(x1-x2)*(x1-x2) + (long long)(y1-y2)*(y1-y2) );
}

int find(int x) {
    if (x == union_find[x])
        return x;
    return union_find[x] = find(union_find[x]);
}

bool merge(int x, int y, double value) {
    x = find(x);
    y = find(y);
    
    if (x == y) return false;
    
    union_find[x] = y;
    if ( find(0) == find(N+1) ) {
        printf("%.6lf \n", value/2);
        return true;
    }
    
    return false;
}


int main(void) {
    
    int T;
    scanf("%d", &T);
    
    while(T--) {
        
        scanf("%d", &W);
        scanf("%d", &N);
        
        vector<vertex_info> arr(N+2);
        vector<info> ans;
        
        if (N == 0) {
            printf("%.6lf\n", (double)W/2);
            continue;
        }

        
        arr[0].x = 0;
        arr[N+1].x = 0;
        for (int i = 1; i <= N; i++) {
            scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].r);
            union_find[i] = i;
        }
        union_find[0] = 0;
        union_find[N+1] = N+1;
        
        
        for (int i = 1; i <= N; i++) {
            int x = arr[i].x;
            int y = arr[i].y;
            int r = arr[i].r;
            
            ans.push_back({i, 0 , (double)max(0, x-r) });
            ans.push_back({i,N+1, (double)max(0, W-(x+r) ) });
            
            for (int j = i+1; j <= N; j++)
                ans.push_back({i,j, max(0.0, distance( x, y, arr[j].x, arr[j].y) - r - arr[j].r) });
        }
        
        sort(ans.begin(), ans.end(), compare_value);
        
        for (int i = 0; i < ans.size(); i++)
            if (merge(ans[i].v1,ans[i].v2,ans[i].value))
                break;
        
    }
    return 0;
}
