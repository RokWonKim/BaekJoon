#include<iostream>
#include<vector>
#include<cmath>
#define max_v 100001

using namespace std;

int N, M;
vector<int> arr[max_v];

// 각 정점의 깊이를 저장
int depth[max_v];

//[정점의][2^i번째 조상] => 최대 십만이니 2의
int ancestor[max_v][18];

//최대 조상값
int level;

void make_lcs(int now, int parent ) {
    
    // 깊이를 저장
    depth[now] = depth[parent]+1;
    // 2^0번째 조상은 parent
    ancestor[now][0] = parent;
    
    for (int i = 1; i <= level; i++) {
        
        // 자신의 조상 값을 저장
        int tmp = ancestor[now][i-1];
        
        // 조상의 2^i-1 값이 곧 자신의 2^i값 => 그만큼 위의 조상값을 가져오기때문에
        // ex) 2^4 조상으 찾고 싶다면 자신의 2^3조상에서 2^3조상만큼 더 올라가야됨
        //     ==    2^3 + 2^3 = 2^4
        ancestor[now][i] = ancestor[tmp][i-1];
    }
    
    
    // 양방향을 지정해줬으니 자신과 연결되 정점중에 parent가 있을 거임 so, 빼고 다 넣음
    for(auto a : arr[now])
        if (a != parent)
            make_lcs(a,now);
    
}

int main(void) {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N-1; i++) {
        int a,b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    // 최대 조상 값
    level = (int)floor(log2(max_v));
    
    make_lcs(1, 0);
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        int value = level;
        
        cin >> a >> b;
        if (depth[a] > depth[b]) swap(a,b);

        // 깊이 맞추기
        // 2^4의 조상에 맞지 않고 2^3조상에 맞다면
        // 2^3으로 이동한뒤에 2^2부터 보면된다
        // why? 위에 설명했던 것처럼 2^3+2^3 = 2^4 이므로 2^3으로 올라가서 2^3 밑부터 보면 된다
        
        while (depth[a] != depth[b]) {
            if (depth[a] <= depth[ancestor[b][value]])
                b = ancestor[b][value];
            value--;
        }
        
        // 위에서 깊이를 맞춰줬음
        // 두 정점 깊이가 같으니 올리다보면 같은 정점에서 만남
        // 일정 수준 이상부터는 조상이 똑같을 거임
        // 즉, ancestor가 다른 순간 그 쪽으로 올려줌( 더 가깝게 움직여줌)
        //  ㄴ 최송 공통 조상에 가깝게 움직여줌
        
        int ans = a;
        
        if (a != b) {
            for (int j = level; j >= 0; j--) {
                if (ancestor[a][j] != ancestor[b][j]) {
                    a = ancestor[a][j];
                    b = ancestor[b][j];
                }
                else
                    ans = ancestor[a][j];
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
