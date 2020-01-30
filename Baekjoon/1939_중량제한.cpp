#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
 
using namespace std;

int weight[100001];
vector<pair<int,int>> arr[100001];
int visit[100001] = {};

bool DFS(int start, int wei, int end) {
    bool result = false;

    if (end == start) {
        return true;
    }
    
    for (int i = 0; i < arr[start].size(); i++) {
        if(visit[arr[start][i].first] == 0 && wei <= arr[start][i].second) {
            visit[arr[start][i].first] = 1;
            result = DFS( arr[start][i].first, wei, end);

            if (result == true) 
                return true;
        }
    }

    return false;
}

int main(void){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    int A,B,C;
    int start,end;
    int max_value = 0;
    
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        arr[A].push_back(pair<int,int>(B,C));
        arr[B].push_back(pair<int,int>(A,C));
        weight[i] = C;
    }

    cin >> start >> end;
    sort(weight, weight+M);

    int left = 0;
    int right = M-1;

    while( left <= right) {

        int mid = (left+right) /2;

        if(DFS(start, weight[mid], end)) {
            max_value = max(max_value, weight[mid]);
            left = mid + 1;
        }
        else
            right = mid -1;

        for(int i = 1; i <= M; i++)
            visit[i] = 0;

        
    }

    cout << max_value;

    
    
    return 0;
}