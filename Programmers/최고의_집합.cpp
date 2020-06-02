#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> answer;


vector<int> solution(int n, int s) {
    
    if (n > s)
        answer.push_back(-1);
    else {
        int value = round(s/n);
        int now = value * n;
        for (int i = 0; i < n; i++)
            answer.push_back(value);
        
        if(now > s) {
            int diff = now-s;
            int i = 0;
            while (diff) {
                answer[i++]--;
                diff--;
            }
        }
        else if (now < s) {
            int diff = s-now;
            int i = answer.size()-1;
            while(diff) {
                answer[i--]++;
                diff--;   
            } 
        }
        
    }
    return answer;
}