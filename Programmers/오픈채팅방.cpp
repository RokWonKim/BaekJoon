#include <map>
#include <string>
#include <vector>

using namespace std;

//uid에 해당하는 아이디
map<string, string> m;
vector<pair<string,string>> v;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for (int i = 0; i < record.size(); i++) {
        string s = record[i];
        vector<string> vs;
        int j = 0;
        int start = 0;
        int count = 0;
        
        for (j = 0; j < s.size(); j++) {
            if (s[j] == ' ' ) {
                vs.push_back(s.substr(start, j-start));
                start = j+1;
                count++;
            }
        }
        vs.push_back(s.substr(start, j-start));
        
        if (vs[0] == "Enter") {
            m[vs[1]] = vs[2];
            v.push_back({vs[1], "님이 들어왔습니다."});
        }
        else if (vs[0] == "Leave")
            v.push_back({vs[1], "님이 나갔습니다."});
        else
            m[vs[1]] = vs[2];
    }
    
    for (int i = 0; i < v.size(); i++)
        answer.push_back(m[v[i].first] + v[i].second);
    
    return answer;
}