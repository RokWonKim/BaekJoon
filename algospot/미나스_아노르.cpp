#include<cstdio>
#include<utility>
#include<algorithm>
#include<cmath>

using namespace std;

const double pi = 2.0 * acos(0);
const int INF = 987654321;

//시작 라디안 부터~ 끝 라디안을 저장
pair<double,double> arr[103];

int solve(double begin, double end, int N) {
    int ans = 0;
    int i = 0;
    while (begin < end) {
        
        double value = -1;
        for (; i < N && arr[i].first <= begin; i++)
            value = max(value, arr[i].second);
        
        if (value <= begin) return INF;
        
        begin = value;
        ans++;
    }
    
    return ans;
}

int main(void) {
    
    int T;
    scanf("%d",&T);
    
    while(T--) {
        int N;
        int ans = INF;
        scanf("%d",&N);
        
        for (int i = 0; i < N; i++) {
            double x,y,r;
            scanf("%lf %lf %lf",&x, &y, &r);
            
            // 점(x,y)과 x축 수평선의 중심각 구하기
            double degree = fmod(2.0*pi + atan2(y,x), 2.0*pi);
            
            // 점(x,y)의 원 안에 들어있는 호의 중심각(라디안)/2
            double range = 2.0* asin( (r/2)/8);
            
            //시작 부터~끝 라디안은 x축 수평부터 반시계방향으로 계산 된다
            arr[i] = {degree-range, degree+range};
        }
        sort(arr, arr+N);
        
        // 0, 2π는 같음 so, 그러한 값중 하나를 골라서 다 확인해봄
        for(int i = 0; i < N; i++) {
            if (arr[i].first <= 0 || arr[i].second >= 2.0*pi) {
                double begin = fmod(arr[i].second, 2.0*pi);
                double end = fmod(arr[i].first+2.0*pi, 2.0*pi);
                
                ans = min(ans, 1 + solve(begin,end,N));
            }
        }
        if (ans == INF)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);
        
    }
    
    return 0;
}
