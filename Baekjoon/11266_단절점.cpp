#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> arr[10001];
bool cutvertex[10001];
int vertex_num[10001];
int num_count = 0;

int confirm(int vertex, bool root) {
    vertex_num[vertex] = num_count++;
    int ret = vertex_num[vertex];
    int child_num = 0;

    for (int i = 0; i < arr[vertex].size(); i++) {
        int next_vertex = arr[vertex][i];

        if (vertex_num[next_vertex] == -1) {
            int child = confirm(next_vertex, false);
            child_num++;

            if (!root && child >= vertex_num[vertex])
                cutvertex[vertex] = true;

            ret = min(child, ret);
        }
        else 
            ret = min(vertex_num[next_vertex],ret);
    }

    if (root) cutvertex[vertex] = (child_num >= 2?true:false);
    return ret;
}


int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(vertex_num, -1, sizeof(vertex_num));
    memset(cutvertex, false, sizeof(cutvertex));

    int A,B;
    int cut_count = 0;
    cin >> A >> B;

    for (int i = 0; i < B; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 1; i <= A; i++) {
        if(vertex_num[i] == -1) {
            confirm(i,true);
        }
    }
    for (int i = 1; i <= A; i++)
        if (cutvertex[i]) cut_count++;
    
    cout << cut_count << '\n';
    for (int i = 1; i <= A; i++)
        if (cutvertex[i]) cout << i << ' ';
    cout << '\n';

    return 0;
}