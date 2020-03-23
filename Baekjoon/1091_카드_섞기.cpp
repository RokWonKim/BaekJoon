#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> arr;
vector<int> change_arr;
int N;
int ans;

bool origin_check(vector<int> &arr_copy) {
    if ( arr_copy == arr)
        return true;
    return false;
}

void change(vector<int> &arr_copy) {

    vector<int> arr_2(arr_copy.size());
    for (int i = 0; i < N; i++) {
        arr_2[ change_arr[i] ] = arr_copy[i];
    }
    arr_copy = arr_2;
}



void check() {

    vector<int> arr_copy = arr;

    while(1) {
        for (int i = 0; i < N; i++) {
            if ( i % 3 == 0) {
                if (arr_copy[i] != 0) break;
            }
            else if( i % 3 == 1) {
                if (arr_copy[i] != 1) break;
            }
            else {
                if (arr_copy[i] != 2) break;
            } 
            if ( i == N-1)
                return;
        }
        if (ans != 0){
            if ( origin_check(arr_copy) ) {
                ans = -1;
                return;
            }
        }
        ans++;
        change( arr_copy );
    }
}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int value;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> value;
        arr.push_back(value);
    }
    for (int i = 0; i < N; i++) {
        cin >> value;
        change_arr.push_back(value);
    }

    check();
    cout << ans;

    return 0;
}