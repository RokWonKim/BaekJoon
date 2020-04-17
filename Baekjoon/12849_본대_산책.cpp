#include<iostream>

using namespace std;

const int m = 1000000007;

int main(void) {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int time;
    cin >> time;
    
    long long arr[8] = {1,0,0,0,0,0,0,0};
    int i = 1;
    while (i <= time) {
        long long now[8]={0,};
        now[0] = (arr[1]+arr[2])%m;
        now[1] = (arr[0]+arr[2]+arr[3])%m;
        now[2] = (arr[0]+arr[1]+arr[3]+arr[4])%m;
        now[3] = (arr[1]+arr[2]+arr[4]+arr[5])%m;
        now[4] = (arr[2]+arr[3]+arr[5]+arr[6])%m;
        now[5] = (arr[3]+arr[4]+arr[7])%m;
        now[6] = (arr[4]+arr[7])%m;
        now[7] = (arr[5]+arr[6])%m;
        
        for (int j = 0; j < 8; j++)
            arr[j] = now[j];
        i++;
    }
    cout << arr[0];
    
    
    
    
    
    
    return 0;
}
