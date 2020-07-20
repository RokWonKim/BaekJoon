#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 987654321;

struct info{
    int v;
    int l;
};

//소각로
info seg[500001*4];
vector<int> answer;

void init(int start, int end, int index, int value, int loc){
    if ( index < start || end < index) return;
    else if (start == end) {
        seg[loc].l = INF;
        seg[loc].v = value;
    }
    else {
        seg[loc].l = INF;
        int mid = (start + end)/2;
        init(start,mid,index,value,loc*2);
        init(mid+1,end,index,value,loc*2+1);
    }
}

void p(int start, int end, int index, int loc) {
    if (seg[loc].l != INF) {
        seg[loc].v = seg[loc].l;
        if (start != end) {
            seg[loc*2].l = seg[loc].l;
            seg[loc*2+1].l = seg[loc].l;
        }
        seg[loc].l = INF;
    }

    if ( index < start || end < index) return;
    else if (start == end) answer.push_back(seg[loc].v);
    else {
        int mid = (start+end)/2;
        p(start, mid, index, loc*2);
        p(mid+1, end, index, loc*2+1);
    }
}

void update(int start, int end, int a, int b, int value, int loc) {
    if (seg[loc].l != INF) {
        seg[loc].v = seg[loc].l;
        if (start != end) {
            seg[loc*2].l = seg[loc].l;
            seg[loc*2+1].l = seg[loc].l;
        }
        seg[loc].l = INF;
    }

    if ( start > b || end < a) return;
    else if (a <= start && end <= b) {
        seg[loc].v = value;
        if (start != end) {
            seg[loc*2].l = value;
            seg[loc*2+1].l = value;
        }
    }
    else {
        int mid = (start+end)/2;
        update(start, mid, a, b, value, loc*2);
        update(mid+1, end, a, b, value, loc*2+1);
    }

}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N,M,K,Q;
    cin >> N >> M >> K >> Q;

    queue<pair<int,int>> q;
    for (int i = 1; i <= N; i++) {
        int v;
        cin >> v;
        if (i > M) q.push({v,1});
        else init(1,M,i,v,1);
    }

    for (int i = 0; i < Q; i++) {
        int num, a, b;
        cin >> num;

        if (num == 1) {
            cin >> a >> b;
            int cnt = b-a+1;

            while(!q.empty() && cnt != 0) {
                int now_cnt = q.front().second;
                int k = q.front().first;

                if (cnt - now_cnt >= 0) {
                    cnt -= now_cnt;
                    update(1,M,a,a+now_cnt-1,k,1);
                    a = a+now_cnt;
                    q.pop();
                }
                else {
                    update(1,M,a,b,k,1);
                    q.front().second -= cnt;
                    cnt = 0;
                }
            }

            if (q.empty() && cnt != 0)
                update(1,M,a,b,0,1);
        }
        else if (num == 2) {
            cin >> a;
            p(1, M, a, 1);
        }
        else if (num == 3) {
            cin >> a >> b;
            q.push({a,b});
        }
        else {
            long long t;
            cin >> t;
            while(t) {
                int now = (long long)q.front().second;
                if ( t-now >= 0) {
                    t -= now;
                    q.pop();
                }
                else {
                    q.front().second -= (int)t;
                    t = 0;
                }
            }

        }
    }

    for (int i : answer)
        cout << i << ' ';
    cout << '\n';

    answer.clear();
    for (int i = 1; i <= M; i++) p(1,M,i,1);
    
    for (int i : answer)
        cout << i << ' ';
    cout << '\n';

    return 0;
}