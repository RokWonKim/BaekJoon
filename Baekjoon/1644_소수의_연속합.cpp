#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N;
vector<int> arr;
vector<int> value;

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;

    cin >> N;
    if (N == 1) {
        cout << 0;
        return 0;
    }

    arr.resize(N+1);
    for (int i = 2; i <= N; i++)
        arr[i] = i;

    for(int i = 2; i <= (int)sqrt(N); i++)
        if (arr[i] != 0)
            for(int j = 2; i*j <= N; j++)
                arr[i*j] = 0;

    for (int i = 2; i <= N; i++)
        if (arr[i] != 0)
            value.push_back(i);

    int start = 0;
    int end = 0;
    int sum = value[0];
    int size = value.size();

    while (1) {
        if (sum < N) {
            end++;
            if (end == size) break;
            sum += value[end];
        }
        else if (sum > N) {
            start++;
            if (start > end) break;
            sum -= value[start-1];
        }
        else {
            ans++;
            end++;
            if (end == size) break;
            sum += value[end];
        }
    }

    cout << ans;

    return 0;
}