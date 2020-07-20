#include <iostream>
#include <string>

using namespace std;

int arr[300001];
int left_po[300001];
int right_po[300001];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N,K;
    string s = "";
    cin >> N >> K;
    K--;

    for (int i = 0; i < N; i++) cin >> arr[i];
    cin >> s;


    // s[i] == 'T'라는 건 왼쪽, 오른쪽 중 이동하여 T를 만날 수 있다는 것
    // 즉, 그 정점에서는 어디로 가든 T사용 가능
    for (int i = 1; i < N; i++) {
        if (arr[i] < arr[i-1]) continue;

        // 왼쪽이 T라면 자신이 밑으로 내려간 후(left)에 트램플린을 쓸 수 있음
        if (s[i-1] == 'T') s[i] = 'T';

        left_po[i] = 1+left_po[i-1];
    }

    for (int i = N-2; i >= 0; i--) {
        if (arr[i] < arr[i+1]) continue;

        if (s[i+1] == 'T') s[i] = 'T';
        right_po[i] = 1 + right_po[i+1];
    }

    int t = 0;
    int best = 0;
    for (int i = 0; i < N; i++) {

        // T라면 트램플린 이용가능 == 들어온 하나는 무조건 사용 가능
        if (s[i] == 'T') t++;
        // T가 아니라는 것 == 마지막으로 들를 것 (트램플린으로 순회 불가능 하니까!)
        // 마지막인 것들 중 최고로 긴것을 고름
        
        // +1해주는 것은 자신을 포함하기 때문
        else best = max(best, 1 + max(left_po[i], right_po[i]) );
    }

    
    if (s[K] == 'T') cout << t+best << '\n';
    // 만약 시작점에서 어떻게 가도 T만날 수 없다
    // 왼쪽이나 우측 중 하나로 가서 가장 높은 것이 답
    else {
        int l = K;
        int r = K;
        // l == r == K가 같다면 그곳은 전부 와리가리로 움직일 수 있음
        while (l > 0 && arr[l-1] == arr[K]) l--;
        while (r < N-1 && arr[r+1] == arr[K]) r++;

        cout << r-l+1+max(left_po[l],right_po[r]);
    }

    return 0;
}