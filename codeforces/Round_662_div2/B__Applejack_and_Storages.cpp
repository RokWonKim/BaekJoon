#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct comp{
    bool operator() (const pair<int,int>& a, const pair<int,int>& b) const{
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
};

set<pair<int,int>, comp> x_num;
int arr[100001];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    x_num.clear();
    memset(arr, 0, sizeof(arr));

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        arr[v]++;
    }

    for (int i = 1; i <= 100000; i++)
        x_num.insert({i,arr[i]});

    set<pair<int,int>>::iterator iter;
    set<pair<int,int>>::iterator iter2;
    set<pair<int,int>>::iterator iter3;
    set<pair<int,int>>::iterator iter4;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char a;
        int b;
        cin >> a >> b;

        if (a == '+') {
            iter = x_num.find({b,arr[b]});
            arr[b]++;

            x_num.erase(iter);
            x_num.insert({b,arr[b]});
        }
        else {
            iter = x_num.find({b,arr[b]});
            arr[b]--;

            x_num.erase(iter);
            x_num.insert({b,arr[b]});
        }
        
        iter = x_num.end();
        iter2 = x_num.end();
        iter3 = x_num.end();
        iter4 = x_num.end();

        iter--;

        iter2--;
        iter2--;

        iter3--;
        iter3--;
        iter3--;

        iter4--;
        iter4--;
        iter4--;
        iter4--;

        if (iter->second >= 8) cout << "YES\n";
        else if (iter->second >= 4 && iter2->second >= 4) cout << "YES\n";
        else if (iter->second >= 6 && iter2->second >= 2) cout << "YES\n";
        else if (iter->second >= 4 && iter2->second >= 2 && iter3->second >= 2) cout << "YES\n";
        else cout << "NO\n";
    }
    

    return 0;
}