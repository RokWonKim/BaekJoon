#include<iostream>
#include<algorithm>

using namespace std;

int k;
int sum_k;
int ans;

int arr[14];
bool check[2600001];


void backtracking(int part_sum, int now_loc){

    if (part_sum > 0){
        check[part_sum] = true;
    }

    for (int i = now_loc; i < k; i++) {
        backtracking(part_sum+arr[i], i+1);
        backtracking(part_sum-arr[i], i+1);
    }

}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        sum_k += arr[i];
    }

    backtracking(0,0);

    for (int i = 1; i <= sum_k; i++) {
        if (check[i] == false)
            ans++;
    }

    cout << ans;

    return 0;
}