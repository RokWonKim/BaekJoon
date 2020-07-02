#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
    int answer = 1;
    sort(weight.begin(), weight.end());
    for (int i : weight) {
        if (answer < i) break;
        answer += i;
    }
    return answer;
}