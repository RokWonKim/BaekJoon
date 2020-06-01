#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector< vector<string> > arr;
vector<int> group_answer;
vector<int> value;
int fullsize = 0;
int answer = 0;

bool confirm_once() {
    map<vector<string>, int> m;
    int sum = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        vector<string> part;
        for(int j = 0; j < value.size(); j++)
            part.push_back(arr[i][value[j]]);
        
        if (m[part] == 0) m[part] = 1;
        else return false;
    }
    for(int j = 0; j < value.size(); j++)
        sum += (1 << value[j]);
    
    for(int i = 0; i < group_answer.size(); i++)
        if ( (sum & group_answer[i]) == group_answer[i]) return true;
    
    group_answer.push_back(sum);
    answer++;
    return true;
}

void backtracking(int index, int size) {
    if (confirm_once()) return;
    if (value.size() == size) return;
    
    for(int i = index; i < fullsize; i++) {
        value.push_back(i);
        backtracking(i+1,size);
        value.pop_back();
    }
    
}

int solution(vector<vector<string>> relation) {
    arr = relation;
    fullsize = relation[0].size();
    for (int i = 1; i <= fullsize; i++)
        backtracking(0,i);
    return answer;
}