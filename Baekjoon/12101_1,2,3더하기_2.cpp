#include<iostream>
#include<vector>

using namespace std;

int n,k;
int ans;
int flag;

int sum;

vector<int> arr;

void print_ans(){
    for (int i = 0; i < arr.size(); i++) {
        if (i < arr.size()-1) 
            cout << arr[i] << '+';
        else
            cout << arr[i];
    }
    flag++;
}

void backtracking(int part_sum) {

    if (part_sum == n) {
        if(++ans == k)
            print_ans();
        return;
    }

    if (part_sum > n)
        return;

    for (int i = 1; i <= 3; i++) {
        arr.push_back(i);
        part_sum += i;
        backtracking(part_sum);
        arr.pop_back();
        part_sum -= i;
    }

}

int main(void){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ans = 0;
    cin >> n >> k;

    backtracking(0);

    if(flag == 0)
        cout << -1;

    return 0;
}