#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
 
using namespace std;

int arr[20000002];
 
int main(void){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;
        arr[num+10000000] = 1;
    }

    int M;
    cin >> M;

    for(int i = 0; i < M; i++) {
        cin >> num;
        if(arr[num+10000000] == 1) {
            cout << 1 << ' ';
        }
        else {
            cout << 0 << ' ';
        }
    }

    
    return 0;
}