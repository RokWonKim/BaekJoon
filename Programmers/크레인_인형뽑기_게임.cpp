#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board[0].size();
    
    stack<int> s;
    for (int i = 0; i < moves.size(); i++) {
        int value = moves[i]-1;
        for (int j = 0; j < size; j++) {
            if (board[j][value] != 0) {
                s.push(board[j][value]);
                board[j][value] = 0;
                break;
            }
        }
        
        if ( s.size() >= 2) {
            
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if (a == b) answer++;
            else {
                s.push(b);
                s.push(a);
            }
        }
        
    }
    return answer*2;
}