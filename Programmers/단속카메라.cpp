#include <string>
#include <vector>
#include <algorithm>

int arr[60002];

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());
    
    int now_end = routes[0][1];
    answer++;
    for (int i = 1; i < routes.size(); i++) {
        if (now_end >= routes[i][1])
            now_end = routes[i][1];
        else if (now_end < routes[i][0]) {
            answer++;
            now_end = routes[i][1];
        }
    }
    
    return answer;
}