#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

int arr[100001];
vector<pair<int,int>> v;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(arr, 0, sizeof(arr));
        v.clear();

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            arr[v]++;
        }
        for (int i = 1; i <= 100000; i++) {
            if (arr[i] != 0)
                v.push_back({arr[i],i});
        }

        sort(v.begin(), v.end());
        int start = 0;
        
        for (int i = v.size()-1; i >= 0; i--) {
            if (v[i].first == v[v.size()-1].first) start = i;
        }

        int between_num = v[v.size()-1].first - 1;
        int diff = v.size()-start -1;
        int el = n - (diff+1)*(between_num+1);

        cout << diff + el/between_num << '\n';

    }

    return 0;
}