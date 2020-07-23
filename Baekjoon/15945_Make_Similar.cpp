#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N; 
    cin >> N;
    
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr+N);

    if (arr[0] == arr[N-1]) cout << 0;
    else if (N == 1) cout << 0;
    else if (arr[0] < 0 && arr[N-1] > 0) cout << 0;
    else {
        int index = 0;
        int last_index = N-1;
        while(arr[index] == 0) index++;
        while(arr[last_index] == 0) last_index--;


        if (arr[index] == arr[last_index]) cout << 0;
        else if (arr[index] > 0) cout << min(arr[index], arr[last_index]-arr[index]);
        else cout << min(-arr[last_index], (-arr[index])-(-arr[last_index]) );

    }
    cout << '\n';

    return 0;
}