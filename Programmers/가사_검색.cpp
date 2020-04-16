#include<bits/stdc++.h>
using namespace std;

int go(map<int,vector<string>>&A,string&q){
    int sz=q.size();
    
    while(sz&&q[sz-1]=='?')
        --sz;
    auto it=A.find(q.size());
    
    if(it==A.end()) return 0;
    else if(sz==0) return it->second.size();
    else{
        auto &a = it->second;
        string s=q.substr(0,sz);
        
        int x=lower_bound(a.begin(),a.end(),s)-a.begin();
        ++s.back();
        int y=lower_bound(a.begin(),a.end(),s)-a.begin();
        
        return y-x;
    }
}

vector<int> solution(vector<string> words, vector<string> queries) {
    map<int, vector<string>> A,B;
    
    sort(words.begin(), words.end());
    
    for(string&w:words){
        A[w.size()].push_back(w);
        reverse(w.begin(),w.end());
    }
    
    sort(words.begin(), words.end());
    for(string&w:words)
        B[w.size()].push_back(w);

    vector<int> ans;
    for(string &q : queries){
        if(q[0]!='?')
            ans.push_back(go(A,q));
        else{
            reverse(q.begin(),q.end());
            ans.push_back(go(B,q));
        }
    }
    return ans;
}
