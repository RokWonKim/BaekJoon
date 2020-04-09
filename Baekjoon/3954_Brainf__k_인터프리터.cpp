#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<string.h>

using namespace std;

int main(void) {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--) {
        
        int m,c,k;
        cin >> m >> c >> k;
        
        //괄호의 짝을 찾아줌
        int where[100001];
               
        vector<int> arr(m, 0);
        vector<char> command(c);
        vector<char> str(k);
        memset(where, 0, sizeof(where));
        
        
        for (int i = 0; i < c; i++)
            cin >> command[i];
        for (int i = 0; i < k; i++)
            cin >> str[i];
        
        stack<int> gualho;
        for (int i = 0; i < c; i++) {
            
            if (command[i] == '[')
                gualho.push(i);
            else if (command[i] == ']') {
                where[i] = gualho.top();
                where[gualho.top()] = i;
                
                gualho.pop();
            }
        }
        
        int progress = 0;
        int pointer = 0;
        int str_locate = 0;
        bool check = false;
        
        for (int i = 1; i <= 50000000; i++) {
            int v = command[progress];
            
            if (progress >= c) {
                check = true;
                cout << "Terminates" << '\n';
                break;
            }
            
            if (v == '-') {
                arr[pointer]--;
                if (arr[pointer] < 0) arr[pointer] = 255;
            }
            else if (v == '+') {
                arr[pointer]++;
                if (arr[pointer] > 255) arr[pointer] = 0;
            }
            else if (v == '<') {
                pointer--;
                if (pointer < 0) pointer = m-1;
            }
            else if (v == '>') {
                pointer++;
                if (pointer == m) pointer = 0;
            }
            else if (v == '[') {
                if (arr[pointer] == 0) progress = where[ progress ];
                else gualho.push(progress);
            }
            else if (v == ']') {
                if (arr[pointer] != 0) progress = where[ progress ];
                else gualho.pop();
            }
            else if (v == ',') {
                if (str_locate < k) {
                    if (str[str_locate] > 255) arr[pointer] = 255;
                    else arr[pointer] = str[str_locate];
                    
                    str_locate++;
                }
                else
                    arr[pointer] = 255;
            }
            
            progress++;
        }
        if (check == false) {
            int a = 0;
            while (!gualho.empty()) {
                a = gualho.top();
                gualho.pop();
            }
            cout << "Loops" << ' ' << a << ' ' << where[a] << '\n';
        }
    }
    
    return 0;
}
