#include<iostream>
#include<string.h>

using namespace std;

int N;
int arr[100002];

int dp[100002][5][5];

int solve(int location, int left_leg, int right_leg) {

    if ( N-1 == location )
        return 0;

    int &value = dp[location][left_leg][right_leg];

    if(value != -1)
        return value;
    
    value = 2100000000;
    int next = location+1;

    if(left_leg == 0 && arr[next] != right_leg )
        value = min(value, solve(next, arr[next], right_leg)+2 );
    if(right_leg == 0 && arr[next] != left_leg )
        value = min(value, solve(next, left_leg, arr[next])+2 );


    if(left_leg == arr[next])
        value = min(value, solve(next, left_leg, right_leg)+1 );
    if(right_leg == arr[next])
        value = min(value, solve(next, left_leg, right_leg)+1 );


    int near_1 = left_leg+1>4 ? left_leg+1-4:left_leg+1;
    int near_2 = left_leg+3>4 ? left_leg+3-4:left_leg+3;
    int far = left_leg+2>4 ? left_leg+2-4:left_leg+2;
    if(left_leg != 0 && ( arr[next] == near_1 || arr[next] == near_2 ) ) {
        if(arr[next] == near_1 && arr[next] != right_leg )
            value=min(value, solve(next, near_1, right_leg)+3 );
        else if (arr[next] == near_2 && arr[next] != right_leg )
            value = min(value, solve(next, near_2, right_leg)+3 );
    }
    if(left_leg != 0 && arr[next] == far && arr[next] != right_leg) {
        value = min(value, solve(next,far,right_leg)+4 );
    }


    near_1 = right_leg+1>4 ? right_leg+1-4:right_leg+1;
    near_2 = right_leg+3>4 ? right_leg+3-4:right_leg+3;
    far = right_leg+2>4 ? right_leg+2-4:right_leg+2;
    if(right_leg != 0 && ( arr[next] == near_1 || arr[next] == near_2) ) {
        if(arr[next] == near_1 && arr[next] != left_leg)
            value = min(value, solve(next, left_leg, near_1)+3 );
        else if (arr[next] == near_2 && arr[next] != left_leg)
            value = min(value, solve(next, left_leg, near_2)+3 );
    }
    if (right_leg != 0 && arr[next] == far && arr[next] != left_leg) {
        value = min(value, solve(next,left_leg, far) + 4);
    }


    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    int a;
    int i = 1;

    arr[0] = 0;
    while(1) {
        cin >> a;
        if (a == 0) break;
        else    arr[i++] = a;
    }
    N = i;

    cout << solve(0,0,0);

    return 0;
}