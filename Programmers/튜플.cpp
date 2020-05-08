#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool number[100001];

struct info {
    int start;
    int end;
    int size;
};

bool compare(const info& a, const info& b) {
    return a.size < b.size;
}

vector<int> solution(string s) {
    vector<int> answer;
    int top_size = 0;
    int top_end = 0;
    int top_start = 0;
    
    int now_size = 0;
    int now_start = 0;
    bool flag = false;
    
    vector< info > v;
    
    for (int i = 1; i < s.size()-1; i++) {
        if (s[i] == '{') {
            now_size = 1;
            now_start = i;
            flag = true;
        }
        else if (s[i] == '}') {
            info a = {now_start+1, i-1 ,now_size};
            v.push_back(a);
            flag = false;
        }
        
        if (flag && s[i] == ',') now_size++;
    }
    
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++) {
        string news = s.substr(v[i].start, v[i].end-v[i].start+1);
        
        int start = 0;
        int incre = 0;
        int now = 0;
        for (int j = 0; j < news.size(); j++) {
            if (news[j] == ','){
                now = stoi(news.substr(start,incre) );
                if (number[now] == false) {
                    answer.push_back(now);
                    number[now] = true;
                }
                incre = 0;
                start = j+1;
            }
            else incre++;
        }
        now = stoi(news.substr(start,incre) );
        if (number[now] == false) {
            answer.push_back(now);
            number[now] = true;
        }   
    }
        
    return answer;
}