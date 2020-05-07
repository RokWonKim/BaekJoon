#include <string>
#include <vector>
#include <utility>
#include <queue>

const int INF = 200000000;
using namespace std;
//인덱스보다 작다면 삭제
struct compare {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b){
        return a.second < b.second;
    }
};


int solution(vector<int> stones, int k) {
    
    int answer = INF;
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> q;
    
    for (int i = 0; i < k; i++)
        q.push({i, stones[i]});
    answer = min(answer,q.top().second);
    for (int i = k; i < stones.size(); i++) {
        q.push({i, stones[i]});
        while (q.top().first <= i-k) {
            q.pop();
        }
        answer = min(answer,q.top().second);
    }
        
    return answer;
}