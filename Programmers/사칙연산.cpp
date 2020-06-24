#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 987654321;

// 0은 큰 수 1은 작은수
int dp[102][102][2];

vector<int> num;
vector<int> oper;

int solve(int start, int end, int now_oper) {
    
    if (end == start) return num[start];
    
    int &value = dp[start][end][now_oper];
    if (now_oper == 0 && value != -INF) return value;
    if (now_oper == 1 && value != INF) return value;
    
    for (int i = start; i < end; i++) {
        if (now_oper == 0) {
            if (oper[i] == 0)
                value = max(value, solve(start,i,0) - solve(i+1, end, 1));
            else 
                value = max(value, solve(start,i,0) + solve(i+1, end,0)); 
        }
        else {
            if (oper[i] == 0)
                value = min(value, solve(start,i,1) - solve(i+1, end, 1));
            else 
                value = min(value, solve(start,i,1) + solve(i+1, end, 1)); 
        }
    }
    
    return value;
}

int solution(vector<string> a) {
    for (int i = 0; i < 102; i++)
        for (int j = 0; j < 102; j++) {
            dp[i][j][0] = -INF;
            dp[i][j][1] = INF;
        }
    
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == "-") oper.push_back(0);
        else if (a[i] == "+") oper.push_back(1);
        else num.push_back( stoi(a[i]) );
    }
    
    return solve(0, num.size()-1, 0);
}