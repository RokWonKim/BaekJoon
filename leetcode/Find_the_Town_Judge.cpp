using namespace std;
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> v(N+1);
        int output = -1;

        for (int i = 0; i < trust.size(); i++) {
            v[trust[i][1]] += 1;
            v[trust[i][0]] -= 1;
        }
        for (int i = 1; i <= N; i++) {
            if(v[i] == N-1)
                output = i;
        }
        return output;
    }
};
