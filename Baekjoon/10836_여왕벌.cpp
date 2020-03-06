#include<iostream>

using namespace std;

int arr[701][701];
int value[1410];

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    int zero,one,two;

    for (int i = 0 ; i < N; i++) {
        cin >> zero >> one >> two;

        for(int j = 0; j < zero+one+two; j++) {
            if ( j <= zero-1 )  value[j] += 0;
            else if ( j <= zero+one-1)  value[j] += 1;
            else    value[j] += 2;
        }
    }

    for (int i = 0; i < 2*M-1; i++) {
        if (i < M) arr[M-1-i][0] = value[i]+1;
        else arr[0][i-M+1] = value[i]+1;
    }

    for(int i = 1; i< M; i++)
        for (int j = 1; j < M; j++)
            arr[i][j] = max(arr[i][j-1],max( arr[i-1][j-1], arr[i-1][j]) );

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}