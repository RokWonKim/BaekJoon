#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct Comparater {
    const vector<int>& group;
    int t;

    Comparater(const vector<int>& _group, int _t) : group(_group), t(_t) {}

    bool operator()(int a, int b) {
        if (group[a] != group[b]) return group[a] < group[b];
        return group[a + t] < group[b + t];
    }
};

vector<int> getSuffixArray(const string& s) {
    int n = s.size();
    int t = 1;
    vector<int> group(n+1);

    for (int i = 0; i < n; i++) group[i] = s[i];
    group[n] = -1;

    //group을 사용하여 각 접미사를 정렬하는 것
    vector<int> perm(n);
    for(int i = 0; i < n; i++) perm[i] = i;

    while(t < n) {

        Comparater compareUsing2T(group, t);
        sort(perm.begin(), perm.end(), compareUsing2T);

        t *= 2;
        if (t >= n) break;

        vector<int> newGroup(n+1);
        newGroup[n] = -1;
        newGroup[perm[0]] = 0;
        
        for (int i = 1; i < n; i++) {

            //제대로 정렬 되어 잇음 => 그대로 써줌
            if (compareUsing2T(perm[i-1], perm[i])) 
                newGroup[perm[i]] = newGroup[perm[i-1]] +1;
            //i번째가 i-1보다 작음 => 바꿔줘야함
            else
                newGroup[perm[i]] = newGroup[perm[i-1]];
        }
        group = newGroup;
    }

    return perm;
}

int commonPrefix(const string& s, int i, int j) {
    int k = 0;

    while(i < s.size() && j < s.size() && s[i] == s[j]) {
        i++; j++; k++;
    }

    return k;
}

int longfrequent(int k, const string &s) {

    vector<int> arr = getSuffixArray(s);
    int ans = 0;
    for (int i = 0; i+k <= s.size(); i++)
        ans = max(ans, commonPrefix(s, arr[i], arr[i+k-1]));

    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int k;
        string str;
        cin >> k;
        cin >> str;

        cout << longfrequent(k, str) << '\n';
    }

    return 0;
}