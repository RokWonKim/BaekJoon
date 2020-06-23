#include <string>
#include <vector>
#include <cstring>

using namespace std;

int s;
int dp[1000000][2];
vector<int> arr;

int solve(int index, int use) {
    
    if (index == s) return 0;
    
    int &value = dp[index][use];
    if (value != -1) return value;
    
    // 난 사용 다음은 미사용
    value = 0;
    if (use == 0)
        value = max(value, solve(index+1, 1)+arr[index]);
    
    value = max(value, solve(index+1, 0));
    
    return value;
}

int solution(vector<int> money) {
    memset(dp, -1, sizeof(dp));
    int answer = 0;
    arr = money;
    
    s = money.size()-1;
    int value = solve(0,0);
    s = money.size();
    memset(dp, -1, sizeof(dp));
    return max(value, solve(1,0));
}