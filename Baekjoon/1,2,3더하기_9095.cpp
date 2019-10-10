#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> v(12);
    for(int i = 1; i <= 11; i++) {
        if(i == 1 || i == 2) v[i] = i;
        else if (i == 3) v[i] = v[i-1]+v[i-2]+1;
        else v[i] = v[i-1] + v[i-2] + v[i-3];
    }
    int N,num;
    cin >> N;
    for(int x = 0; x < N; x++) {
        cin >> num;
        cout << v[num] << endl;
    }
    return 0;
}
