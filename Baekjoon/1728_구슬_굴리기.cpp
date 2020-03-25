#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

vector<int> arr;
vector< multiset<int> > v;

int N;
int now;

//몇번째인지 , 값이 몇인지, 몇 차이나는지
bool backtracking(int size, int value, int diff) {

    if (size == N) {
        cout << arr[now] << ' ' << diff << '\n';
        return true;
    }

    if (size == 0) {
        for (auto iter = v[0].begin(); iter != v[0].end(); ++iter) {
            int diff_value = *iter - value;
            if (backtracking(1,*iter, diff_value)) {
                v[0].erase(iter);
                return true;
            }
        }
    }
    else {
        auto iter = v[size].find(value+diff);
        if (iter != v[size].end()) {
            if (backtracking(size+1, *iter, diff)) {
                v[size].erase(iter);
                return true;
            }
            else return false;
        }
    }

    return false;

}

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int value;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> value;
        arr.push_back(value);
    }
    sort(arr.begin(), arr.end());

    for (int i = 1; i <= N; i++) {
        multiset<int> s;
        for (int i = 0; i < N; i++) {
            cin >> value;
            s.insert(value);
        }
        v.push_back(s);
    }

    for (int i = 0; i < N; i++) {
        now = i;
        backtracking(0, arr[i], 0);
    }

    return 0;
}