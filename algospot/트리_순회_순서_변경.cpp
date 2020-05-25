#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> slice(const vector<int>& arr, int a, int b) {
    return vector<int>(arr.begin()+a, arr.begin() + b);
}

void printpostorder(const vector<int>& preorder, const vector<int>& middleorder) {

    int n = preorder.size();
    if (n == 0) return;

    int root = preorder[0];
    int left = find(middleorder.begin(), middleorder.end(), root) - middleorder.begin();
    int right = n-1-left;

    printpostorder( slice(preorder,1,left+1), slice(middleorder,0,left));
    printpostorder( slice(preorder,left+1, n), slice(middleorder,left+1,n));

    cout << root << ' ';
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> preorder(n);
        vector<int> middleorder(n);

        //전위 순회
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        //중위 순회
        for (int i = 0; i < n; i++)
            cin >> middleorder[i];
        
        printpostorder(preorder, middleorder);
        cout << '\n';        

    }

    return 0;
}