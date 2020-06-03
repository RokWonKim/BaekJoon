#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX_V = 100001;

int nextnum;
int all_n;
vector<int> child[MAX_V];

// 서로를 맵핑해 놓기 주어지는 노드와 직접 주어질 노드
int no_to_se[MAX_V];
int se_to_no[MAX_V];

// 각 노드가 처음 등장하는 위치, 노드의 깊이
int locate[MAX_V];
int dep[MAX_V];

struct RMQ {
    int n;
    vector<int> arr;

    RMQ(const vector<int> &array) {
        n = array.size();
        all_n = n;
        arr.resize(n*4);
        init(array,0,n-1, 0);
    }

    int init(const vector<int> &array, int left, int right, int index) {
        if (left == right)
            return arr[index] = array[left];

        int mid = (left + right) / 2;
        int nextleft = init(array, left, mid, index*2+1);
        int nextright = init(array, mid + 1, right, index*2+2);

        return arr[index] = min(nextleft, nextright);
    }

    int lca(int index, int left, int right, int start, int end) {
        if (right < start || end < left)
            return INF;
        else if ( start >= left && end <= right)
            return arr[index];
        
        int mid = (start+end)/2;
        return min( lca(index*2+1, left, right, start, mid), lca(index*2+2, left, right, mid+1, end));
    }

};


void traverse(int here, int depth, vector<int>& trip) {

    no_to_se[here] = nextnum;
    se_to_no[nextnum] = here;
    nextnum++;
    
    dep[here] = depth;

    locate[here] = trip.size();
    trip.push_back(no_to_se[here]);

    for (int next_ver : child[here]) {
        traverse(next_ver, depth+1,trip);
        trip.push_back(no_to_se[here]);
    }
}

RMQ *prepareRMQ() {
    nextnum=0;
    vector<int> trip;
    traverse(0,0,trip);
    return new RMQ(trip);
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n ,q;
        nextnum = 0;
        cin >> n >> q;

        for (int i = 0; i < MAX_V; i++) child[i].clear();

        for (int i = 1; i < n; i++) {
            int parent;
            cin >> parent;
            child[parent].push_back(i);
        }

        RMQ *now = prepareRMQ();

        for (int i = 0; i < q; i++) {
            int a,b;
            cin >> a >> b;

            int u = locate[a];
            int v = locate[b];
            if (u > v) swap(u,v);

            int value = se_to_no[now->lca(0, u, v, 0, all_n-1)];
            cout << dep[a] + dep[b] - 2*dep[value] << '\n';
        }


    }
    return 0;
}