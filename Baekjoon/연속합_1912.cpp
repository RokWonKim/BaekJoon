#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    
    vector<int> v(N+1);
    vector<int> re_v(N+1);
    
    for(int i = 1; i <= N; i++)
        cin >> v[i];
    
    int max_return = v[1];
    re_v[1] = v[1];
    
    for (int i = 2; i <= N; i++){
        if(v[i] >= 0) re_v[i] = max(re_v[i-1]+v[i], v[i]);
        else {
            if (re_v[i-1] + v[i] > 0) re_v[i] = re_v[i-1]+v[i];
            else re_v[i] = v[i];
        }
        max_return = max(max_return, re_v[i]);
    }
    cout << max_return;
    return 0;
}
