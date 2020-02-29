#include<iostream>
#include<cmath>

using namespace std;

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[n+1];

    for (int i = 0; i <= n; i++)
        arr[i] = 100000000;

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++) {
        for(int j = 1; j*j <= i; j++) {
            arr[i] = min(arr[i] , arr[i - j*j]);
        }
        arr[i]++;
    }

    cout << arr[n];



    return 0;
}