#include<iostream>
#include<vector>
#include<cmath>
#include<string.h>

using namespace std;

int N;

// 센터까지의 거리
int distan[20001];

// 자신의 루트
int parent[20001];

int find(int x) {
    if (parent[x] == x)
        return x;
    else {
        int tmp = find(parent[x]);
        
        // 부모의 값 ~ 센터까지의 거리를 얻은 다음에
        distan[x] += distan[parent[x]];
        
        // 루트를 저장함
        parent[x] = tmp;
        return tmp;
    }
}

void merge(int x, int y) {
    distan[x] = abs(x-y) % 1000;
    parent[x] = y;
}

int main(void) {
    
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        cin >> N;
        
        for (int i = 1; i <= N; i++ )
            parent[i] = i;
        memset(distan, 0, sizeof(distan));
        
        while(1) {
            char c;
            cin >> c;
            if (c == 'O') break;
            else if (c == 'E') {
                int a;
                cin >> a;
                find(a);
                cout << distan[a] << '\n';
            }
            else {
                int a, b;
                cin >> a >> b;
                merge(a,b);
            }
        }
        
    }

    return 0;
}
