#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int tree_size[10001];
int union_find[10001];
int enemy[10001];
int answer_size;

int find(int x) {
    if (union_find[x] == x) return x;
    return union_find[x] = find(union_find[x]);
}

int merge(int a, int b) {
    if (a == -1 || b == -1) return max(a,b);
    a = find(a);
    b = find(b);

    if (a != b) {
        union_find[a] = b;
        tree_size[b] += tree_size[a];
        return b;
    }
    else return a;
}

bool ack(int a, int b) {
    a = find(a);
    b = find(b);

    if (enemy[a] == b) return true;

    int v_1 = merge(a,b);
    int v_2 = merge(enemy[a],enemy[b]);
    enemy[v_1] = v_2;
    if(v_2 != -1)enemy[v_2] = v_1;

    return false;
}
bool dis(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return true;

    int v_1 = merge(a, enemy[b]);
    int v_2 = merge(b, enemy[a]);
    enemy[v_1] = v_2;
    enemy[v_2] = v_1;

    return false;
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(enemy, -1, sizeof(enemy));
        int N, M;
        bool flag = false;
        int index = 0;
        answer_size = 0;

        cin >> N >> M;

        for (int i = 0; i < N; i++) {
            union_find[i] = i;
            tree_size[i] = 1;
        }

        for (int i = 0; i < M; i++) {
            string s;
            int a, b;
            cin >> s >> a >> b;

            if (flag == true) continue;

            //true 면 flag = true로 만들고 
            if (s == "ACK") flag = ack(a,b);
            else flag = dis(a,b);

            if (flag == true) index = i+1;
        }

        int answer = 0;
        
        for (int i = 0; i < N; i++) {
            if (find(i) == i) {
                int e = enemy[i];
                if (e > i) continue;

                int siz = tree_size[i];
                int e_siz = e==-1?0:tree_size[e];
                answer += max(siz, e_siz);
            }
        }
        

        if (flag)
            cout << "CONTRADICTION AT " << index << '\n';
        else
            cout << "MAX PARTY SIZE IS " << answer << '\n';   
    }

    return 0;
}