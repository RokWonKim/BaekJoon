#include <string>
#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int user_size, banned_size;
vector< vector<int> > arr(9);
vector<int> tracking;
bool confirm[9];
bool char_confirm[1<<9];

void gogogo() {
    int value = 0;
    for (int i = 0; i < 9; i++) {
        if (confirm[i])
            value += (1 << i);
    }
    
    if (char_confirm[value] == false) {
        char_confirm[value] = true;
        answer++;   
    }
    
}

bool string_compare(string& a, string& b) {
    if (a.size() != b.size() )
        return false;
    
    for(int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) continue;
        else if ( a[i] == '*') continue;
        return false;
    }
    return true;
}

void backtracking(int ban_index) {
    if (ban_index == banned_size) {
        gogogo();
        return;
    }
        
    for (int a : arr[ban_index]) {
        if (confirm[a] == true) continue;
        
        confirm[a] = true;
        backtracking(ban_index+1);
        confirm[a] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    banned_size = banned_id.size();
    for(int i = 0; i < banned_id.size(); i++)
        for (int j = 0; j < user_id.size(); j++)
            if (string_compare(banned_id[i], user_id[j]) )
                arr[i].push_back(j);
    
    backtracking(0);
    
    return answer;
    
}