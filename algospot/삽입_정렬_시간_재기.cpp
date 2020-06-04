#include <iostream>
#include <vector>

using namespace std;

struct Fenwick {
    vector<int> tree;
    Fenwick(int n) : tree(n+1){}

    int sum (int pos) {
        pos++;
        int result = 0;
        while(pos > 0) {
            result+= tree[pos];
            pos &= (pos-1);
        }
        return result;
    }

    void add (int pos, int val) {
        pos++;
        while(pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }

};

long long countMoves(const vector<int> &A) {
    Fenwick tree(1000000);
    long long result = 0;
    for (int i = 0; i < A.size(); i++) {
        // 각 수의 움직인 횟수를 더함
        result += tree.sum(999999) - tree.sum(A[i]);
        tree.add(A[i],1);
    }
    return result;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector<int> A(N,0);

        for(int i = 0; i < N; i++)
            cin >> A[i];

        cout << countMoves(A) << '\n';

    }

    return 0;
}