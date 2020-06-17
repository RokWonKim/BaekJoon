#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct info{
    int x;
    int y;
    int wei;
};

int answer;
int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int parent[100000];
int ver_rank[100000];
int sum_val[100000];
vector<info> arr;


bool compare(const info& a, const info& b) {
    return a.wei < b.wei;
}

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y, int wei) {
    x = find(x);
    y = find(y);
    
    if (x == y) return;
    
    if (ver_rank[x] < ver_rank[y]) swap(x,y);
    ver_rank[x] += ver_rank[y];
    sum_val[x] += sum_val[y] + wei;
    answer = sum_val[x];
    parent[y] = x;
}

int solution(vector<vector<int>> land, int height) {
    int N = land.size();
    for (int i = 0; i < N*N; i++) {
        parent[i] = i;
        ver_rank[i] = 1;
        sum_val[i] = 0;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            
            for (int z = 0; z < 4; z++) {
                int x = i + d[z][0];
                int y = j + d[z][1];
                int value = 0;
                if (x >= N || x < 0 || y >= N || y < 0) continue;
                if ( abs(land[i][j] - land[x][y]) > height )
                    value = abs(land[i][j] - land[x][y]);
                arr.push_back({i*N+j, x*N+y, value});
            }
        }
    }
    
    sort(arr.begin(), arr.end(), compare);
    
    for (int i = 0; i < arr.size(); i++)
        merge(arr[i].x, arr[i].y, arr[i].wei);
    
    return answer;
}