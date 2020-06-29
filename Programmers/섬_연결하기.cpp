#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer;
int parent[101];

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y, int cost) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    answer+=cost;
    parent[x] = y;
}

int solution(int n, vector<vector<int>> costs) {
    sort(costs.begin(), costs.end(), compare);
    for (int i = 0; i < n; i++) parent[i] = i;
    for (int i = 0; i < costs.size(); i++)
        merge(costs[i][0], costs[i][1], costs[i][2]);
    return answer;
}