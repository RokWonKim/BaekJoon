#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

pair<int,int> arr[1000];

int main(void) {

    int T;
    scanf("%d", &T);
    while(T--) {
        int n,k;
        scanf("%d %d", &n, &k);

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &arr[i].first, &arr[i].second);
        }

        double left = 0;
        double right = 1;
        double mid = 0;
        for (int i = 0;i < 100; i++) {
            vector<double> value;

            mid = (left+right)/2;
            double sum = 0;
            for (int j = 0; j < n; j++)
                value.push_back(mid*arr[j].second - arr[j].first);
            sort(value.begin(), value.end());

            for (int j = n-1; j >= 0; j--) {
                sum += value[j];
                if ( j <= n-k && sum >= 0) break;
            }
                
            if (sum >= 0) right = mid;
            else left = mid;
        }

        printf("%.8lf\n", right);

    }




    return 0;
}