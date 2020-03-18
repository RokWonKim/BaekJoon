#include<iostream>
#include<string>
#include<string.h>

using namespace std;

const int INF = 210000000;

string str;
int dp[2002];


bool palindrom(int start, int end) {
    string part = str.substr(start,end-start+1);
    int size = part.size();

    for (int i = 0; i < size/2; i++) {
        if(part[i] != part[size-1-i])
            return false;
    }
    return true;
}

int solve(int end) {

    if (end == str.size()) 
        return 0;

    int &value = dp[end];
    if (value != -1)
        return value;
    
    value = INF;
    for (int i = end; i < str.size(); i++)
        if (palindrom(end, i))
            value = min(value, solve(i+1) + 1);

    return value;
}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    
    cin >> str;

    cout << solve(0);

    return 0;
}