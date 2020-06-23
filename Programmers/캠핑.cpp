#include <vector>
#include <algorithm>

using namespace std;

bool compare_1(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}
bool compare_2(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}

int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    sort(data.begin(), data.end(), compare_1);
    
    for (int i = 0; i < data.size(); i++) {
        int x = data[i][0];
        int y = data[i][1];
        int bottom = -1;
        
        for (int j = i+1; j < data.size(); j++) {
            if (x < data[j][0] && y != data[j][1] && y > data[j][1] && bottom <= data[j][1]) {
                bottom = data[j][1];
                answer++;
            }
        }
    }
    
    sort(data.begin(), data.end(), compare_2);
    for (int i = 0; i < data.size(); i++) {
        int x = data[i][0];
        int y = data[i][1];
        long long top = 10000000000;
        
        for (int j = i+1; j < data.size(); j++) {
            if (x < data[j][0] && y != data[j][1] && y < data[j][1] && top >= ((long long)data[j][1])) {
                top = (long long)data[j][1];
                answer++;
            }
        }
    }
    
    return answer;
}