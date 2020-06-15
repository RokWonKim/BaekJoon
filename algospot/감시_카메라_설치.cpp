#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> arr[1000];

int num_count;
bool visited[1000];

int confirm(int vertex) {
    visited[vertex] = true;
    // 0 자식이 감시되고 있는지?
    // 1 자식이 감시되고 있지않다?
    // 2 자식에 cctv가 설치되어있나?
    bool check[3] = {false, };

    for (int i = 0; i < arr[vertex].size(); i++) {
        int next_vertex = arr[vertex][i];
        
        if (!visited[next_vertex])
            check[confirm(next_vertex)] = true;
    }

    if (check[1]) {
        num_count++;
        return 2;
    }
    else if (check[2]) return 0;

    return 1;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < 1000; i++) arr[i].clear();
        num_count = 0;

        int G, H;
        cin >> G >> H;
        for (int i = 0; i < H; i++) {
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        for (int i = 0; i < G; i++)
            if (!visited[i])
                if (confirm(i) == 1) num_count++;
        
        cout << num_count << '\n';
    }

    return 0;
}