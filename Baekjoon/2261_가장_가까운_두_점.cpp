#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>

#define INF 2100000000

using  namespace std;

int distance_cal(pair<int,int> i, pair<int,int> j) {
    return pow(i.first-j.first,2) + pow(i.second-j.second,2);
}

int main(void) {

    int n;
    int ans = 0;
    int x_limit = 0;

    cin >> n;

    vector< pair<int,int> > arr(n);
    map< pair<int, int>, bool > m;

    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    sort( arr.begin(), arr.end() );

    ans = distance_cal(arr[0], arr[1]);


    //y중심으로 확인을 할 것인데 정렬 기준이 첫번재 인자이므로 띠로 정렬 기준 선언하는것보다 더 좋음
    m[{arr[0].second, arr[0].first}] = true;
    m[{arr[1].second, arr[1].first}] = true;

    for (int line = 2; line < n; line++) {

        //x값끼리의 뺄셈으로 1차적으로 거르기 => 
        while ( x_limit < line) {

            // (x값 차)^2이 ans 보다 작으면 가능성이 있으므로 (가정하는 것)
            // 뒤에 있는 값들은 당연 (x값 차)가 더 작으므로 그대로 break;

            // 즉, sqrt(ans) >= (x값 차)
            if (pow(arr[x_limit].first - arr[line].first,2) <= ans)
                break;

            // (y값 차)는 볼것도 없이 아웃시키기
            m.erase({arr[x_limit].second, arr[x_limit].first});

            //다음 확인하기
            x_limit++;
        }

        //이제 (x값 차)는 가능성이 있는 것들로 구성됨
        //so, (y값 차)도 확인하기

        int y_limit = sqrt(ans); 

        // (y값 차) 기준으로 위아래 다 확인하기
        // y값도 ans를 넘어서면 쓸모없으므로 거르기
        auto down = m.lower_bound({arr[line].second - y_limit, -INF});
        auto up = m.upper_bound({arr[line].second + y_limit, INF});

        for (auto iter = down; iter != up; ++iter) {
            //key 값 가져오기
            pair<int,int> key = (*iter).first;
            ans = min( ans, distance_cal( arr[line], {key.second, key.first} ) );
        }
        
        // 다음 line을 위해 추가
        m[{arr[line].second, arr[line].first}] = 1;
    }

    cout << ans;

    return 0;
}