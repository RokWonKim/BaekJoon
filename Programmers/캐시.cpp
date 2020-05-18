#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int ans = 0;
    
    map<string, int> m;
    set<int> s;
    queue<int> q;
    vector<int> arr;
    
    int number = 1;
    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities[i].size(); j++) {
            if ('A' <= cities[i][j] && cities[i][j] <= 'Z' )
                cities[i][j] += 32;
        }
        if (m[cities[i]] == 0) m[cities[i]] = number++;
        arr.push_back(m[cities[i]]);
    }
    
    if (cacheSize == 0) return arr.size()*5;
    
    for (int i = 0; i < arr.size(); i++) {
        int value = arr[i];
        
        if (s.find(value) != s.end()) {
            ans += 1;
            
            queue<int> index;
            while(!q.empty()) {
                int wait = q.front();
                q.pop();
                index.push(wait);
            }
            while(!index.empty()) {
                int wait = index.front();
                index.pop();
                if (wait != value) q.push(wait);
            }
            q.push(value);
          
        }
        else {
            ans += 5;
            if (q.size() == cacheSize) {
                int a = q.front();
                q.pop();
                s.erase(a);
            }
            
            q.push(value);
            s.insert(value);
        }
        
    }
    return ans;
}