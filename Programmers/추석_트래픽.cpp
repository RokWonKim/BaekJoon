#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int,int>> arr;
    multiset<int> times;
    
    for (int i = 0; i < lines.size(); i++) {
        string s = lines[i];
        int end = 0;
        int back = 0;
        end += stoi(s.substr(11,2)) * 60*60*1000;
        end += stoi(s.substr(14,2)) * 60*1000;
        end += stoi(s.substr(17,2))*1000 + stoi(s.substr(20,3));
        back += stoi(s.substr(24,1)) * 1000;
        
        string wait = "";
        for (int j = 26; j < s.size()-1; j++) wait += s[j];
        while(wait.size() != 3) wait += "0";
        
        back += stoi(wait);
        back = end - back + 1;
        
        arr.push_back({back, end});
    }
    sort(arr.begin(), arr.end());
    
    
    for (int i = 0; i < arr.size(); i++) {
        int start = arr[i].first;
        int end = arr[i].second;
        
        times.insert(end);
        auto iter = times.lower_bound(start-1000);
        if (*iter <= start-1000) ++iter;
        
        if (times.size() != 1 ) times.erase(times.begin(), iter);
        int value = (int)times.size();
        
        answer = max(answer,value);
    }
    
 
    return answer;
}