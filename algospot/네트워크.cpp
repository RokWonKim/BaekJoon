#include <string>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int> > arr;
bool check[201];
int answer = 0;

void BFS(int index) {
    answer++;
    
    queue<int> q;
    q.push(index);
    
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        
        if (check[v] == true) continue;
        check[v] = true;
        
        for(int i = 0; i < arr.size(); i++)
            if (check[i] == false && arr[v][i] == 1)
                q.push(i);
    }
    
}


int solution(int n, vector<vector<int>> computers) {
    
    arr = computers;
    
    for (int i = 0; i < n; i++)
        if (check[i] == false) BFS(i);
    
    return answer;
}