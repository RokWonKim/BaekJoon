#include<iostream>

using namespace std;

int N;
int mul;
int start;
int arr[10];

void cal(int value) {
    
    while ( value > 0 ) {
        arr[value % 10] += mul;
        value /= 10;
    }
    
}

int main(void) {
    
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    mul = 1;
    start = 1;
    
    while (start <= N) {
        while (N%10 != 9 && start < N) {
            cal(N);
            N--;
        }
        
        while (start%10 != 0 && start <= N) {
            cal(start);
            start++;
        }
        if (N < start) break;
        
        start /= 10;
        N /= 10;
        
        for (int i = 0; i < 10; i++)
            arr[i] += (N-start+1) * mul;
        
        mul *= 10;
    }
    
    for (int i = 0; i < 10; i++)
        cout << arr[i] << ' ';
    
    return 0;
}
