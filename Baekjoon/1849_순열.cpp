#include <iostream>
#include <algorithm>

using namespace std;

int seg[4 * 100000];
int arr[100001];

int update(int pos, int val, int node, int x, int y) {
    if (y < pos || pos < x)
        return seg[node];
    if (x == y)
        return seg[node] = val;
    int mid = (x + y) >> 1;
    return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}

int query(int val, int node, int x, int y) {
    int mid = (x + y) >> 1;
    if (x == y)
        return x;
    else if (seg[node * 2] >= val)
        return query(val, node * 2, x, mid);
    return query(val - seg[node * 2], node * 2 + 1, mid + 1, y);
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) update(i, 1, 1, 1, n);

    for (int i = 1; i <= n; i++) {
        cin >> x;
        int q = query(x + 1, 1, 1, n);
        arr[q] = i;
        update(q, 0, 1, 1, n);
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] <<'\n';

    return 0;
}