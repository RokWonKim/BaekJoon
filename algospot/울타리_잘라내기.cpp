#include<iostream>
#include<vector>

using namespace std;

int arr[20001];
int ans = 0;

void solve(int left, int right) {
    
    if (left == right) {
        ans = max(ans, arr[left]);
        return;
    }
    
    int mid = (left+right)/2;
    
    solve(left, mid);
    solve(mid+1, right);
    
    int height = arr[mid];
    int left_point = mid;
    int right_point = mid;
    
    while (left_point > left || right_point < right ) {
        int value = 0;
        if (left_point > left && right_point < right) {
            if (arr[left_point-1] > arr[right_point+1])
                value = arr[--left_point];
            else
                value = arr[++right_point];
        }
        else if (left_point > left)
            value = arr[--left_point];
        else
            value = arr[++right_point];
        
        height = min(value,height);
        ans = max(ans,(right_point-left_point+1)*height);
        
    }
    
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        
        int N;
        cin >> N;
        
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        
        solve(0,N-1);
        cout << ans <<'\n';
        
        ans = 0;
    }
    
    return 0;
}
