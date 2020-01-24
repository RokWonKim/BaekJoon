#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<utility>
 
using namespace std;

bool b(const pair<int, string>& i, const pair<int, string>& j) {
    return i.first < j.first;
}
 
int main(void){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int num = 0;
    string str = "";

    vector< pair<int, string> > arr(N);
    
    for(int i = 0; i < N; i++) {
        
        cin >> num;
        cin >> str;
        arr[i] = pair<int, string>(num, str);
    }

    stable_sort(arr.begin(), arr.end(), b);

    for(int i = 0; i < N; i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
    

 
    return 0;
}