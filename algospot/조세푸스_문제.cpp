#include<iostream>
#include<list>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {

        int n, k;
        cin >> n >> k;

        list<int> li;

        for (int i = 1; i <= n; i++) li.push_back(i);

        list<int>::iterator iter = li.begin();
        while(li.size() > 2) {
            iter = li.erase(iter);
            if (iter == li.end()) iter = li.begin();
            for (int i = 1; i < k; i++) {
                iter++;
                if(iter == li.end()) iter = li.begin();
            }
        }
        iter = li.begin();
        cout << li.front() << ' ' << li.back() << '\n';

    }

    return 0;
}