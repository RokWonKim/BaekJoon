#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int parent[500];
int rank_ver[500];
pair<int,int> arr[500];
double answer;

double cal(const pair<int,int>& a, const pair<int,int>& b){
    return sqrt( (double)(pow(a.first-b.first,2) + pow(a.second-b.second,2)) );
}

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return false;
    
    if (rank_ver[x] < rank_ver[y]) swap(x,y);
    rank_ver[x] += rank_ver[y]; 
    parent[y] = x;

    return true;
}

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        answer = 0;
        vector<pair<double,pair<int,int>> > v;

        for (int i = 0; i < N; i++){
            int a;
            scanf("%d", &a);
            parent[i] = i;
            rank_ver[i] = 1;
            arr[i].first = a;
        }
        for (int i = 0; i < N; i++) {
            int a;
            scanf("%d", &a);
            arr[i].second = a;
        }

        for (int i = 0; i < M; i++) {
            int a,b;
            scanf("%d %d", &a, &b);
            merge(a,b);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                v.push_back({cal(arr[i],arr[j]),{i,j}});
            }
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++) {
            if (merge(v[i].second.first, v[i].second.second)) {
                answer += v[i].first;
            }
        }

        printf("%.8lf\n", answer);

    }

    return 0;
}