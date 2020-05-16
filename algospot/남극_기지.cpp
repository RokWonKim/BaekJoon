#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

struct info{
    int x;
    int y;
    double len;
};

pair<double,double> arr[100];
vector<info> len;
int union_find[10000];
double ans;

bool compare(const info& a,  const info& b){
    return a.len < b.len;
}

int find(int x) {
    if ( union_find[x] == x) return x;
    return union_find[x] = find(union_find[x]);
}

void merge(int x, int y, double length) {
    x = find(x);
    y = find(y);

    if (x != y) {
        union_find[x] = y;
        ans = length;
    }
}

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        len.clear();
        ans = 0;
        int N;
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            scanf("%lf %lf", &arr[i].first, &arr[i].second);
            union_find[i] = i;
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                double a = sqrt(pow(arr[i].first-arr[j].first,2) + pow(arr[i].second-arr[j].second,2));
                len.push_back({i,j,a});
            }
        }

        sort(len.begin(), len.end(), compare);

        for (int i = 0; i < len.size(); i++) {
            int x = len[i].x;
            int y = len[i].y;
            double length = len[i].len;

            merge(x,y, length);
        }

        printf("%.2lf\n", ans);
    }

    return 0;
}