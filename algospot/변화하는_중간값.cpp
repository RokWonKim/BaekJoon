#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const long long mod = 20090711;

struct compare {
    bool operator()(const long long a, const long long b)const {
        return a > b;
    }
};

int main(void) {
    ios_base:: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N;
        long long a,b;
        long long sum = 1983;
        long long part = 1983;

        cin >> N >> a >> b;
        
        //작은 값들의 최대 힙 => 항상 이 값만 봄
        priority_queue<long long> max_heap;
        //큰 값들의 최소 힙
        priority_queue<long long, vector<long long>, compare > min_heap;
        max_heap.push(part);
        for (int i = 1; i < N; i++) {
            part = (part*a+b) % mod;
            if (i % 2 == 1) min_heap.push(part);
            else max_heap.push(part);
            
            if (max_heap.top() > min_heap.top()) {
                int first = max_heap.top();
                int second = min_heap.top();
                max_heap.pop();
                min_heap.pop();
                max_heap.push(second);
                min_heap.push(first);
            }
            
            sum = (sum + max_heap.top()) % mod;
        }

        cout << sum << '\n';

    }


    return 0;
}