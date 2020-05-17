#include<cstdio>
#include<vector>

using namespace std;

struct point {
    double x,y;
};

int n, m;
// 두 껍질의 좌표를 저장
vector<point> hull1,hull2;
// 껍질안에서 x좌표가 증가하면 밑으로 볼록, 감소하면 위로 볼록 => 시계반대방향으로 값이 주어짐
vector<pair<point,point>> low_hull, high_hull;

// 껍질 안에서 오목한 부분과 볼록한 부분을 나눔
void calcul(const vector<point>& hull, int size) {
    for (int i = 0; i < size; i++) {
        if (hull[i].x < hull[(i+1) % size].x)
            low_hull.push_back({ hull[i], hull[(i+1) % size] });
        else if (hull[i].x > hull[(i+1) % size].x)
            high_hull.push_back({ hull[i], hull[(i+1) % size] });
    }
}

// 수직선과 교차하는지
bool exist(const point& a, const point& b, double x) {
    return (a.x <= x && x <= b.x) || (b.x <= x && x <= a.x);
}

// 두 점의 좌표(일차 방정식)가 주어졌을때 그 우의 점 x좌표로 y좌표 구하기
double y_value(const point& a, const point& b, double x) {
    double dy = b.y - a.y;
    double dx = b.x - a.x;

    return a.y + dy*(x - a.x)/dx;
}

//수진선 위의 점의 차 
double confirm(double value) {
    
    double high = 1e20;
    double low = -1e20;

    for (int i = 0; i < high_hull.size(); i++)
        if (exist(high_hull[i].first,high_hull[i].second, value))
            high = min(high, y_value(high_hull[i].first,high_hull[i].second, value));

    for (int i = 0; i <low_hull.size(); i++)
        if (exist(low_hull[i].first,low_hull[i].second, value))
            low = max(low, y_value(low_hull[i].first,low_hull[i].second, value));

    return high - low;
}

int main(void) {

    int T;
    scanf("%d", &T);
    while(T--) {
        hull1.clear();
        hull2.clear();
        low_hull.clear();
        high_hull.clear();

        double hull1_minx = 101;
        double hull1_maxx = -1;

        double hull2_minx = 101;
        double hull2_maxx = -1;
        
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            double a,b;
            scanf("%lf %lf", &a, &b);
            hull1_minx = min(hull1_minx, a);
            hull1_maxx = max(hull1_maxx, a);

            hull1.push_back({a,b});
        }

        for (int i = 0; i < m; i++) {
            double a,b;
            scanf("%lf %lf", &a, &b);
            hull2_minx = min(hull2_minx, a);
            hull2_maxx = max(hull2_maxx, a);

            hull2.push_back({a,b});
        }
        calcul(hull1, n);
        calcul(hull2, m);


        // x를 기준으로 확인함
        // 삼분 탐색
        double left = max(hull1_minx, hull2_minx);
        double right = min(hull2_maxx, hull1_maxx);
        for (int i = 0; i < 100; i++) {
            double p1 = (left*2+right) / 3.0;
            double p2 = (left + right*2) / 3.0;

            if (confirm(p1) < confirm(p2)) left = p1;
            else right = p2;
        }

        printf("%.9lf\n", max(0.0, confirm(right)));

    }

    return 0;
}