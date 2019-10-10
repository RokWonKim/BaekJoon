#include<iostream>
#include<vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> v0(N+1);
    vector<int> v1(N+1);
    v0[0] = 1;
    v1[1] = 1;
    for(int i = 2; i <= N; i++) {
        v0[i] = v0[i-1] + v0[i-2];
        v1[i] = v1[i-1] + v1[i-2];
    }
    int num;
    for(int i = 0; i < N; i++){
        cin >> num;
        cout << v0[num]<<" "<<v1[num]<<endl;
    }
    return 0;
}
