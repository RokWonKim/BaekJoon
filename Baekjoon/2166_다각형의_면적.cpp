#include <cstdio>
#include <vector>
#define x first
#define y second

using namespace std;

vector<pair<double,double>> arr;

double solve(pair<double,double>& p1, pair<double,double>& p2, pair<double,double>& p3 ) {
    return ((p2.x-p1.x)*(p3.y-p1.y) - (p2.y-p1.y)*(p3.x-p1.x))/2.0;
}

int main(void) {
    int N;
    scanf("%d", &N);
    double answer = 0;
    
    for (int i = 0; i < N; i++) {
        double a, b;
        scanf("%lf %lf", &a, &b);
        arr.push_back({a,b});
    }

    for (int i = 1; i <= arr.size()-2; i++)
        answer += solve(arr[0], arr[i], arr[i+1] );

    printf("%.1lf", answer > 0 ? answer : -answer);

    return 0;
}