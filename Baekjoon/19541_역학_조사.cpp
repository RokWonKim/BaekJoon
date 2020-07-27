
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#define MAX 100001

using namespace std;

int N, M;
int arr[MAX];
int answer[MAX];
int e[MAX];
bool check[MAX];

vector<int> v[MAX];

bool solve() {
    for (int i = 1; i <= N; i++)
        if (arr[i] != e[i]) return false;
    return true;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int a;
            cin >> a;
            v[i].push_back(a);
            check[a] = true;
        }
    }

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        e[i] = 1;
    }

    for (int i = M-1; i >= 0; i--) {
        bool flag = false;

        for (int j : v[i])
            if (arr[j] == 0 || e[j] == 0) flag = true;

        if (flag) {
            for(int j : v[i]) e[j] = 0;
        }
    }

    // 어떤 모임도 가지지 않은 사람들은 최종값을 그대로 따름
    for (int i = 1; i <= N; i++) {
        answer[i] = e[i];
        if (!check[i]) {
            answer[i] = arr[i];
            e[i] = arr[i];
        }
    }

    for (int i = 0; i < M; i++) {
        bool flag = false;

        for (int j : v[i])
            if (e[j] == 1) flag = true;
        
        if (flag) {
            for(int j : v[i]) e[j] = 1;
        }
    }

    if(!solve()) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 1; i <= N; i++) cout << answer[i] << ' ';
        cout << '\n';
    }

    return 0;
}